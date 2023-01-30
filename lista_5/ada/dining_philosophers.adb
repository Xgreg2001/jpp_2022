with Ada.Numerics.Float_Random; use Ada.Numerics.Float_Random;
with Ada.Text_IO;               use Ada.Text_IO;

procedure Dining_Philosophers is
    protected type Fork is
        entry Grab;
        procedure Put_Down;
    private
        Seized : Boolean := False;
    end Fork;
    protected body Fork is
        entry Grab when not Seized is
        begin
            Seized := True;
        end Grab;
        procedure Put_Down is
        begin
            Seized := False;
        end Put_Down;
    end Fork;

    Life_Span        : constant := 10;
    Num_Philosophers : constant := 3;

    task type Person
       (ID : Integer; First, Second : not null access Fork);
    task body Person is
        Dice : Generator;
    begin
        Reset (Dice);
        for Life_Cycle in 1 .. Life_Span loop
            Put_Line (Integer'Image (ID) & " is thinking");
            delay Duration (Random (Dice) * 0.100);
            Put_Line (Integer'Image (ID) & " is hungry");
            First.Grab;
            Second.Grab;
            Put_Line (Integer'Image (ID) & " is eating");
            delay Duration (Random (Dice) * 0.100);
            Second.Put_Down;
            First.Put_Down;
        end loop;
        Put_Line (Integer'Image (ID) & " is leaving");
    end Person;

    Forks : array (1 .. Num_Philosophers) of aliased Fork;
    type PhilosopherArray is
       array (1 .. Num_Philosophers) of access Person;
    philosophers : PhilosopherArray;

begin
    for i in 1 .. Num_Philosophers loop
        if i = Num_Philosophers then
            philosophers (i) :=
               new Person (i, Forks (i)'Access, Forks (1)'Access);
        else
            philosophers (i) :=
               new Person (i, Forks (i)'Access, Forks (i + 1)'Access);
        end if;
    end loop;
end Dining_Philosophers;
