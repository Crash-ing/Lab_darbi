##    Māris Priede, mp24063
##    A22. Doti veseli skaitļi  m un n. Izdrukāt tos skaitļus, kuri atrodas intervālā [n,m] un ir veselu skaitļu kubi.
##    Programma izveidota: 20.09.2024

while True:   
    
    # Pārbauda, vai mainīgā ievade bija veiksmīga 
    while True:
        try:    
            x = int(input("Input x value: "))
            break
        except ValueError:
            print("Error! You didn't input a valid integer! Try again!")

    while True:
        try:
            y = int(input("Input y value: "))
            break
        except ValueError:
            print("Error! You didn't enter a valid integer! Try again!")

    # Pārliecinās par to, lai y vieenmēr būtu lielāks.
    if x > y:
        x, y = y, x

    for x in range(x, y + 1):
        if x < 0:
            # Pārbauda negatīvos kubus
            i = -1
            while True:
                cube = i ** 3
                i = i - 1
                if cube <= x: break
        else:
            # Pārbauda pozitīvos kubus
            i = 0
            while True:
                cube = i ** 3
                i = i + 1
                if cube >= x: break

        if cube == x:
            print(x)

    # Cikls, lai lietotājs varētu turpināt darbu, neaizverot programmu.
    while True:    
        try:    
            restart = int(input("Do you want to restart (1) or end (0)?"))
            # Ja ievada 1, tad iziet no cikla un atkārto programmu. Ja ievada 0, tad iziet no cikla un beidz programmu.
            if restart == 0 or restart == 1:
                break
            else:
                print("Error! You need to enter 1 to restart or 0 to end the program!")
        except ValueError:
            print("Error! You need to enter 1 to restart or 0 to end the program!")
    
    if restart == 0:
        print("End of program!")
        break
