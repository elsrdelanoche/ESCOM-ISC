import tkinter as tk

app =tk.Tk()
palabra=tk.StringVar(app)
entrada=tk.StringVar(app)
#Proporcionamos dimensiones
app.geometry("300x600") 
app.configure(background="black")
#app.configure(background="black")
tk.Wm.wm_title(app, "Alfredo Bautista")


tk.Button(
    #Le indicamos donde estara
    app, 
    text="Click me",
    font=("Courier",14),
    bg="#00a8e8",
    fg="white",
    command=lambda: print("Hola bro" + entrada.get()),
    relief="flat",
).pack(
    fill=tk.BOTH,
    expand=True,
)
tk.Label(
    app,
    text="Hey tag",
    fg="white",
    bg="black",
    justify="center"
).pack(
    fill=tk.BOTH,
    expand=True,
)
tk.Entry(
    fg="white",
    bg="black",
    justify="center",
    textvariable=entrada,
).pack(
    fill=tk.BOTH,
    expand=True,
)

#Ira refrescando la app
app.mainloop()  