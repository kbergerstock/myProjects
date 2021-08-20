namespace FSharp.hat

open System
open System.Drawing
open System.Windows.Forms

type public Drawhat() as draw =
    new() = 
        let XP = 300.0
        let YP = 110.0
        let ZP = 90.0
        let XR = 1.5 * System.Math.PI
        let YR = 1.0
        let xf = XR / YP
        let yf = YP / YR
        let zf = XP / ZP
        let xp2 = XP * XP

    let calcCY hgt =
        ((( hgt / 2.0) * 9.0 ) / 10.0)

    let calcCX width =
        width / 2.0

    let event_draw_hat(sender:obj,e:PaintEventArgs) =
    (
    )


    

    


