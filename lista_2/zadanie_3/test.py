from finite_field import finite_field


def main():

    assert finite_field(1234567891) == finite_field(0)

    assert finite_field(1) + finite_field(2) == finite_field(3)
    assert finite_field(1234567890) + finite_field(4) == finite_field(3)

    assert finite_field(1) - finite_field(2) == finite_field(1234567890)
    assert finite_field(1234567890) - \
        finite_field(4) == finite_field(1234567886)

    assert finite_field(1) * finite_field(2) == finite_field(2)
    assert finite_field(1234567890) * finite_field(4) == -finite_field(4)
    assert finite_field(1234567890) * \
        finite_field(1234567890) == finite_field(1)

    assert finite_field(1).inverse() == finite_field(1)
    assert finite_field(2).inverse() == finite_field(617283946)

    assert finite_field(1) / finite_field(2) == finite_field(617283946)
    assert finite_field(1234567890) / \
        finite_field(4) == finite_field(925925918)

    assert finite_field(1) ** finite_field(2) == finite_field(1)
    assert finite_field(1234567890) ** finite_field(4) == finite_field(1)

    assert finite_field(1) < finite_field(2)

    assert finite_field(1) <= finite_field(2)

    assert finite_field(2) > finite_field(1)

    assert finite_field(2) >= finite_field(1)

    assert finite_field(1) != finite_field(2)

    assert finite_field(1) == finite_field(1)

    assert str(finite_field(2)) == "2"


if __name__ == '__main__':
    main()
