namespace FSharp.hat

open System
open System.Drawing
open System.Windows.Forms

open Drawhat

type public MainForm() as form =
    inherit Form()

    // TODO define your controls
    let plot = new PictureBox() 
    let label = new Label()

    // TODO initialize your controls
    let initControls() = 
        plot.BackColor <- Color.Black
        plot.Size <- System.Drawing.Size(800,600)
       

    do
        form.SuspendLayout();
        initControls()

        // TODO add controls to the form
        form.Controls.Add(plot)

        // TODO define form properties
        form.ClientSize <- new Size(800, 600)
        form.Text <- "F# Hat"
        form.BackColor <- Color.CadetBlue

        // TODO define any required for events
        plot.Paint.AddHandler(new System.Windows.Forms.PaintEventHandler
            ( fun sender e -> plot.event_draw_hat(sender, e)))

        form.Load.AddHandler(new System.EventHandler 
            (fun sender e -> form.eventForm_Loading(sender, e)))


        // render the form
        form.ResumeLayout(false)
        form.PerformLayout()

    // TODO define your event handlers
    member form.eventForm_Loading(sender:obj, e:EventArgs) = 
        (            
        )

          