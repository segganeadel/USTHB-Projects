import pandas as pd
import pathlib as pl
from scipy.io import arff
from mlxtend.frequent_patterns import apriori


def execute_algorithm(algorithm, file, minsup):
    df = load_file(file.name)
    return apply_algorithm(algorithm, df, minsup)

def load_file(path):
    if pl.Path(path.name).suffix == ".csv":
        df = pd.read_csv(path.name)
    if pl.Path(path.name).suffix == ".arff":
        df = load_arff(path.name)
    return df

def load_arff(path):    
    data = arff.loadarff(path)
    df = pd.DataFrame(data[0])
    for col, dtype in df.dtypes.items():
        if dtype == object:  # Only process object columns.
            df[col] = df[col].str.decode('utf-8')
    return df

def discretize(df):
    for col, dtype in df.dtypes.items():
        if dtype == float or dtype == int:
            df[col] = pd.cut(df[col], 4,precision=0)
    return df

def apply_algorithm(algorithm, df, minsup):
    if algorithm == "Apriori":
        df = discretize(df)
        df = apriori(df, min_support=minsup, use_colnames=True)
    if algorithm == "Closed":
        df = discretize(df)
        df = apriori(df, min_support=minsup, use_colnames=True, closed=True)
    return df
