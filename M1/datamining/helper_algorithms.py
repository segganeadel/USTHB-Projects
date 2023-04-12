import pandas as pd
import pathlib as pl
from scipy.io import arff
from mlxtend.frequent_patterns import association_rules
from algorithms import apriori, aprioriclose, dict_to_df

#  This function is called by gradio
def execute_algorithm(algorithm, file, minsup, auto_minsup, rule_numb, confidence):
    df = load_file(file)
    return apply_algorithm(algorithm, df, minsup, auto_minsup, rule_numb, confidence)



def apply_algorithm(algorithm, df, minsup, auto_minsup, rule_numb, confidence):

    df = discretize(df)
    df = pd.get_dummies(df,dtype=bool,sparse=True)
    iterations = 0

    if auto_minsup:
        minsup = 0.05
        if algorithm == "Apriori":
            while True:
                minsup += 0.05
                iterations += 1               
                itemset_dict,support_dict = apriori(df, min_support=minsup, use_colnames=True)
                result = dict_to_df(df, itemset_dict, support_dict, use_colnames=True)
                rules = association_rules(result, metric="confidence", min_threshold = confidence)
                rules.insert(loc=0, column='index', value=rules.index)
                if rules.shape[0] <= rule_numb:
                    break

        if algorithm == "Closed":
            while True:
                iterations += 1
                itemset_dict,support_dict = aprioriclose(df, min_support=minsup, use_colnames=True)
                result = dict_to_df(df, itemset_dict, support_dict, use_colnames=True)
                rules = association_rules(result, metric="confidence", min_threshold = confidence)
                if rules.shape[1] >= rule_numb:
                    break
                minsup += 0.05            
    else :
        if algorithm == "Apriori":
            itemset_dict,support_dict = apriori(df, min_support=minsup, use_colnames=True)
            result = dict_to_df(df, itemset_dict, support_dict, use_colnames=True)
            rules = association_rules(result, metric="confidence", min_threshold = confidence)
            rules.insert(loc=0, column='index', value=rules.index)
        if algorithm == "Closed":
            itemset_dict,support_dict = aprioriclose(df, min_support=minsup, use_colnames=True)
            result = dict_to_df(df, itemset_dict, support_dict, use_colnames=True)
            rules = association_rules(result, metric="confidence", min_threshold = confidence)
            rules.insert(loc=0, column='index', value=rules.index)

    return iterations,minsup,result,rules



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
