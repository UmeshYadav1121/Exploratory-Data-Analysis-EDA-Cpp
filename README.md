# Exploratory Data Analysis (EDA) System in C++

A standalone C++ analytics engine for executing Exploratory Data Analysis (EDA), computing summary statistics, and measuring correlation coefficients.

## Overview
Exploratory Data Analysis is a crucial primary step in data analytics used to summarize main numerical characteristics of a dataset. This project processes an employee metrics dataset to compute corporate summary statistics and analyze relationships between work experience and compensation.

## Key Features
- **Descriptive Statistics:** Calculates totals, mean averages, and min/max ranges across employee profiles.
- **Pearson Correlation Engine:** Implements the mathematical Pearson Correlation Coefficient formula to quantify linear relationships between metrics.
- **Data-Driven Insights:** Automates metric analysis to provide textual interpretation of statistical results.
- **Terminal Scatter Plot:** Renders an ASCII coordinate grid visualizing distribution trends directly in the command line.

## Mathematical Formulation
The linear correlation between variables $X$ (Experience) and $Y$ (Salary) is computed as:
$$r = \frac{n\sum(XY) - \sum X\sum Y}{\sqrt{[n\sum(X^2) - (\sum X)^2][n\sum(Y^2) - (\sum Y)^2]}}$$

## Project Structure
- `main.cpp`: Complete C++ implementation containing dataset vectors, statistical aggregators, covariance logic, and terminal grid plotting.
- `README.md`: Project documentation.

## How to Run
Compile and run using any standard C++ compiler (C++11 or later):
```bash
g++ main.cpp -o eda_analysis
./eda_analysis
