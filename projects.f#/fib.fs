open System

let factorial n =
        let rec  rfactorial x acc =
                if x <= 1I then
                        acc
                else
                        rfactorial (x - 1I) (acc * x)

        rfactorial n 1I


let fib1 n =
        let rec next f0 f1 x =
                match x with
                | x when x < 1I -> 1I
                | x when x = 1I -> f0 + f1
                | _ -> next f1 ( f0 + f1) ( x - 1I)

        if n = 0I then 0I
        else next 1I 1I ( n - 2I)

let fib2 n =
    let rec next a1 a2 cnt =
        if (cnt<1) then 1
        elif (cnt=1) then a1+a2
        else next a2 (a1+a2) (cnt-1)
    if n = 0 then 0
    else next 1 1 (n-2)

let writeFactorial n =
        Console.WriteLine("factorial {0} : {1}", n ,(factorial n ) )

let writeFibonacci n =
        Console.WriteLine("fibanocci {0} : {1}", n ,(fib1 n ) )


let main() =
	nl = [0I..25I]
	List.map writeFactorial nl
	List.map writeFibonacci nl

main()


