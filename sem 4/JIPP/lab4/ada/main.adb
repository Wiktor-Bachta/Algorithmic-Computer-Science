with Ada.Numerics.Float_Random; use Ada.Numerics.Float_Random;
with Ada.Text_IO;               use Ada.Text_IO;
with Ada.Containers.Vectors;    use Ada.Containers;

procedure Main is

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

    Life_Span : constant := 3;

    task type Person (ID : Integer; First, Second : not null access Fork);
    task body Person is
        Dice : Generator;
    begin
        Reset (Dice);
        for Life_Cycle in 1 .. Life_Span loop
            Put_Line (Integer'Image (ID) & " is thinking");
            delay Duration (Random (Dice) * 0.100);
            Put_Line (Integer'Image (ID) & " is hungry");
            Put_Line (Integer'Image (ID) & " is trying to grab first fork");
            First.Grab;
            Put_Line (Integer'Image (ID) & " is trying to grab second fork");
            Second.Grab;
            Put_Line (Integer'Image (ID) & " is eating");
            delay Duration (Random (Dice) * 0.100);
            Put_Line (Integer'Image (ID) & " is putting down first fork");
            First.Put_Down;
            Put_Line (Integer'Image (ID) & " is putting down second fork");
            Second.Put_Down;
            Put_Line (Integer'Image (ID) & " has eaten");
        end loop;
    end Person;

    Num_Philosophers : constant := 5;
    Forks            : array (1 .. Num_Philosophers) of aliased Fork;
    Philosophers     : array (1 .. Num_Philosophers) of access Person;
begin
    for I in 1 .. Num_Philosophers loop
        if I mod 2 = 0 then -- If even philosopher, left-handed
            Philosophers (I) :=
               new Person
                  (I, Forks (I)'Access,
                   Forks ((I mod Num_Philosophers) + 1)'Access);
        else -- If odd philosopher, right-handed
            Philosophers (I) :=
               new Person
                  (I, Forks ((I mod Num_Philosophers) + 1)'Access,
                   Forks (I)'Access);
        end if;
    end loop;
    null;
end Main;
