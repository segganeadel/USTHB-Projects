import gradio as gr
from helper_algorithms import execute_algorithm



inputs = [
    gr.Radio(["Apriori","Closed"],value="Apriori",label="Algorithme"),

    gr.File(label="Fichier ARFF ou CSV"),

    gr.Slider(
        value=0.1,
        label="Lower bound minsup",
        minimum=0.01,
        maximum=1,
        step=0.01),

    gr.Checkbox(label="Auto Minsup",value=True),

    gr.Number(label="Number of rules (if minsup set on auto)",value=10),

    gr.Slider(
        value=0.9,
        label="Min conf",
        maximum=1,
        step=0.01),
    ]


outputs = [
    gr.Number(label="Iterations"),
    gr.Number(label="Minsup"),
    gr.Dataframe(label="Dataframe",type="pandas",max_rows=5),
    gr.Dataframe(label="Dataframe",type="pandas",max_rows=5),
    ]

demo = gr.Interface(execute_algorithm,
                    inputs,
                    outputs)

demo.launch()

    