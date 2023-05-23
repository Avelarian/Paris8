# Liste d'exercises - Programmation des composants embarqués

## Ian Avelar Peixoto

### Exercise 1

```vhdl
entity circuit is
    port (
        A, B, C : in std_logic;
        M : out std_logic
    );
end circuit;

architecture behavior of circuit is
begin
    process (A, B, C)
    begin
        case (A & B & C) is
            when "000" => M <= '0';
            when "001" => M <= '0';
            when "010" => M <= '0';
            when "011" => M <= '1';
            when "100" => M <= '0';
            when "101" => M <= '1';
            when "110" => M <= '1';
            when "111" => M <= '1';
            when others => M <= 'X';
        end case;
    end process;
end behavior;
```

On commence par définir une entité appelée circuit qui a trois entrées (A, B, C) et une sortie (M). Cela définit simplement les ports que le circuit utilisera pour communiquer avec l'extérieur.

Ensuite, l'architecture du circuit est définie avec le nom behavior. À l'intérieur de l'architecture, un process est défini. Ce processus est le cœur du circuit et définit comment les entrées sont combinées pour produire la sortie.

Le processus est déclenché chaque fois qu'il y a un changement dans l'une des entrées (A, B ou C). Lorsqu'il est déclenché, il utilise une instruction case pour déterminer quelle valeur doit être attribuée à la sortie (M).

Le case examine toutes les combinaisons possibles d'entrées (A, B et C) et attribue la valeur appropriée à la sortie (M). Par exemple, lorsque les entrées sont A = 0, B = 1 et C = 1, le code correspondant est :

```vhdl
when "011" => M <= '1';
```

Cela signifie que la sortie M doit être mise à 1 lorsque les entrées sont A = 0, B = 1 et C = 1. Chaque ligne dans le case correspond à une ligne de la table de vérité donnée.

Enfin, il y a une ligne when others => M <= 'X';. Cela signifie que si aucune des combinaisons d'entrées ne correspond à l'un des cas spécifiés, la sortie M doit être mise à "indéfinie" ('X' en VHDL). Cela garantit que le circuit est bien défini pour toutes les combinaisons possibles d'entrées.

En résumé, le code VHDL fourni correspond à la table de vérité donnée en examinant toutes les combinaisons possibles d'entrées et en attribuant la sortie appropriée en fonction de ces entrées.

### Exercise 2

```vhdl
entity comparateur is
    port (A, B: in std_logic_vector(1 downto 0);
          agb, alb, aeb: out std_logic);
end entity comparateur;

architecture behavior of comparateur is
begin
    agb <= '1' when A > B else '0';
    alb <= '1' when A < B else '0';
    aeb <= '1' when A = B else '0';
end architecture behavior;
```

Le code VHDL pour le comparateur implémente la table de vérité donnée car il utilise des opérations de comparaison pour attribuer les valeurs appropriées aux sorties agb, alb et aeb en fonction des valeurs d'entrée A et B. Plus précisément :

La ligne agb <= '1' when A > B else '0'; attribue la valeur '1' à la sortie agb si A est supérieur à B, sinon elle attribue la valeur '0'.
La ligne alb <= '1' when A < B else '0'; attribue la valeur '1' à la sortie alb si A est inférieur à B, sinon elle attribue la valeur '0'.
La ligne aeb <= '1' when A = B else '0'; attribue la valeur '1' à la sortie aeb si A est égal à B, sinon elle attribue la valeur '0'.
En examinant la table de vérité donnée, nous pouvons voir que pour chaque combinaison d'entrée A et B, les sorties agb, alb et aeb sont correctement définies en fonction de si A est supérieur, inférieur ou égal à B. Par exemple, lorsque A=0 et B=1, la sortie agb doit être '0' (car A n'est pas supérieur à B), la sortie alb doit être '1' (car A est inférieur à B) et la sortie aeb doit être '0' (car A n'est pas égal à B). Ces sorties sont correctement définies dans le code VHDL, ce qui signifie que le circuit implémente correctement la table de vérité donnée.

En fin de compte, le code VHDL fourni est un exemple de la façon dont un circuit de comparaison peut être implémenté en utilisant des opérations de comparaison standard dans VHDL.

### Exercise 3

### Exercise 4

```vhdl
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Compteur_Circulaire is
    port (
        clk     : in  std_logic;
        reset   : in  std_logic;
        count   : out integer range 0 to 20
    );
end Compteur_Circulaire;

architecture Behavioral of Compteur_Circulaire is
    signal internal_count : integer range 0 to 20 := 0;
begin
    process(clk, reset)
    begin
        if reset = '1' then   -- Reset actif à l'état haut
            internal_count <= 0;
        elsif rising_edge(clk) then
            if internal_count = 0 then
                internal_count <= 20;
            else
                internal_count <= internal_count - 1;
            end if;
        end if;
    end process;

    count <= internal_count;
end Behavioral;
```

Explications du code :

L'entité Compteur_Circulaire a trois ports : une entrée d'horloge clk, une entrée de réinitialisation reset et une sortie de comptage count.

L'architecture Behavioral utilise une signal interne internal_count pour stocker la valeur actuelle du compteur, initialement définie à 0.

Le processus utilise une condition if pour tester si reset est actif (à l'état haut) et réinitialiser internal_count à 0 si c'est le cas.

Sinon, le processus utilise la fonction rising_edge pour détecter un front montant de clk. Si internal_count est actuellement égal à 0, le compteur est réinitialisé à 20. Sinon, internal_count est décrémenté de 1.
La valeur finale de internal_count est affectée à la sortie count.

Avec ce code, chaque fois que le front descendant d'horloge se produit, le compteur décrémente de 1 jusqu'à ce qu'il atteigne 0. À ce stade, le compteur est automatiquement réinitialisé à 20 et le processus recommence. Ainsi, le décompte circulaire de 20 à 0 puis retour à 20 est réalisé.

### Exercise 5

À partir de l'image de l'énoncé il a été possible de faire la table de vérité suivante:

| C2 | C1 | C0 | S0 | S1 | S2 | S3 | S4 | S5 | S6 | S7 |
| - | - | -  | - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |

Et donc, écrire le code suivant :

```vhdl
entity truth_table is
    Port ( C0, C1, C2 : in  std_logic;
           S0, S1, S2, S3, S4, S5, S6, S7 : out std_logic);
end truth_table;

architecture Behavioral of truth_table is
begin
    S0 <= not C0 and not C1 and not C2;
    S1 <= C0 and not C1 and not C2;
    S2 <= not C0 and C1 and not C2;
    S3 <= C0 and C1 and not C2;
    S4 <= not C0 and not C1 and C2;
    S5 <= C0 and not C1 and C2;
    S6 <= not C0 and C1 and C2;
    S7 <= C0 and C1 and C2;
end Behavioral;
```

Ce code est destiné à concevoir une table de vérité à partir de trois entrées, C0, C1 et C2, et de huit sorties, S0 à S7. Dans cet exemple, chaque sortie est basée sur les entrées C0, C1 et C2. Le but est de concevoir une table de vérité pour chaque combinaison possible des entrées, ce qui signifie qu'il y aura huit sorties différentes pour chaque combinaison.

L'entité truth_table définit les ports d'entrée et de sortie du circuit logique. Les ports d'entrée sont C0, C1 et C2, qui sont de type std_logic. Les ports de sortie sont S0 à S7, également de type std_logic.

L'architecture Behavioral du truth_table contient le code qui décrit comment les sorties sont calculées en fonction des entrées. Les sorties S0 à S7 sont définies à l'aide d'opérateurs logiques tels que AND et NOT. Par exemple, S0 est défini comme étant égal à NOT C0 AND NOT C1 AND NOT C2, ce qui signifie que S0 sera égal à 1 (TRUE) lorsque C0, C1 et C2 sont tous à 0 (FALSE).
