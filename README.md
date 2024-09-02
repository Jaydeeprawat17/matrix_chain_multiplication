# Matrix Chain Multiplication

This repository contains a C++ implementation of the Matrix Chain Multiplication algorithm. This algorithm helps in finding the optimal way to multiply a given sequence of matrices such that the total number of scalar multiplications is minimized.

## Table of Contents

- [About the Algorithm](#about-the-algorithm)
- [Features](#features)
- [Usage](#usage)
- [Example Input And Output](#example-input-and-output)

## About the Algorithm

Matrix Chain Multiplication is an optimization problem that can be solved using dynamic programming. Given a sequence of matrices, the goal is to determine the most efficient way to multiply these matrices together. The solution involves finding the order of matrix multiplications that minimizes the total number of scalar multiplications.

## Features

- **Input Types**: Allows users to input matrix dimensions either by specifying matrix order types or directly providing matrix positions.
- **Dynamic Programming Approach**: Utilizes dynamic programming to compute the minimum number of multiplications required.
- **Optimal Parenthesization**: Outputs the optimal parenthesization for the matrix multiplication.

## Usage

### Requirements

- Turbo C++ or any C++ compiler that supports `<conio.h>`.
- Basic understanding of matrix operations and dynamic programming.

### Example Input And Output

**Input**
```bash
Select Input Type
1) Matrix Order Types Values:(2*3,3*4,4*5)
2) Direct Position:(2 3 4 5)
1 Enter The Matrix Order
2*3,3*4,4*5
```
**Output**
```bash
Optimal Parenthesization: ((A1A2)(A3A4))A5
Minimum number of multiplications: 124
Code Explanation
The program consists of several key components:
```
**Structures:**
```bash
String: To handle input strings and compute their length.
position: Stores matrix positions and names.
matrix: Stores computed values and the split index for matrices.
Class MatrixChain: Manages the entire matrix chain multiplication process including input handling, dynamic programming calculations, and result output.

Dynamic Programming Table: A table is constructed to store minimum multiplication costs and splitting points, which are then used to construct the optimal multiplication order.
```
