from finite_field import finite_field


def main():

    assert finite_field(1234567891, 1234567891) == finite_field(0, 1234567891)

    assert finite_field(1, 1234567891) + finite_field(2,
                                                      1234567891) == finite_field(3, 1234567891)
    assert finite_field(1234567890, 1234567891) + \
        finite_field(4, 1234567891) == finite_field(3, 1234567891)

    assert finite_field(1, 1234567891) - \
        finite_field(2, 1234567891) == finite_field(1234567890, 1234567891)
    assert finite_field(1234567890, 1234567891) - \
        finite_field(4, 1234567891) == finite_field(1234567886, 1234567891)

    assert finite_field(1, 1234567891) * finite_field(2,
                                                      1234567891) == finite_field(2, 1234567891)
    assert finite_field(1234567890, 1234567891) * \
        finite_field(4, 1234567891) == -finite_field(4, 1234567891)
    assert finite_field(1234567890, 1234567891) * \
        finite_field(1234567890, 1234567891) == finite_field(1, 1234567891)

    assert finite_field(1, 1234567891).inverse() == finite_field(1, 1234567891)
    assert finite_field(2, 1234567891).inverse(
    ) == finite_field(617283946, 1234567891)

    assert finite_field(1, 1234567891) / \
        finite_field(2, 1234567891) == finite_field(617283946, 1234567891)
    assert finite_field(1234567890, 1234567891) / \
        finite_field(4, 1234567891) == finite_field(925925918, 1234567891)

    assert finite_field(1, 1234567891) ** finite_field(2,
                                                       1234567891) == finite_field(1, 1234567891)
    assert finite_field(
        1234567890, 1234567891) ** finite_field(4, 1234567891) == finite_field(1, 1234567891)

    assert finite_field(1, 1234567891) < finite_field(2, 1234567891)

    assert finite_field(1, 1234567891) <= finite_field(2, 1234567891)

    assert finite_field(2, 1234567891) > finite_field(1, 1234567891)

    assert finite_field(2, 1234567891) >= finite_field(1, 1234567891)

    assert finite_field(1, 1234567891) != finite_field(2, 1234567891)

    assert finite_field(1, 1234567891) == finite_field(1, 1234567891)

    assert str(finite_field(2, 1234567891)) == "2"


if __name__ == '__main__':
    main()
