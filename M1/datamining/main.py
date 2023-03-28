import gradio as gr
from algorithms import execute_algorithm



inputs = [
    gr.Radio(["Apriori","Closed"],label="Algorithme"),
    gr.File(label="Fichier ARFF ou CSV"),
    gr.Slider(label="Minimum support",
              info="0:Auto",
                maximum=1, step=0.01),
    ]

outputs = [
    gr.Dataframe(label="Dataframe",type="pandas")
    ]

demo = gr.Interface(execute_algorithm,
                    inputs,
                    outputs)

demo.launch()

    