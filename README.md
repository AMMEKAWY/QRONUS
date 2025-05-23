# QRONUS: Quantum-Based Scattering in C++

## Overview
QRONUS is a computational framework designed for quantum-based scattering analysis using C++. It provides a refined approach to solving the Schrödinger equation efficiently and accurately for various scattering scenarios, moving beyond traditional methods like the Lippmann-Schwinger integral equation.

## Features
- **Phase Shift Analysis** replacing the Born Approximation for cross-section evaluation.
- **Numerical Solution** using Frobenius-derived initial conditions and RK4 integration.
- **Optimized Potential Models** reducing charged particle-atom interaction to a two-body problem.
- **Performance Validation** with results benchmarked against NIST data.

## Implementation Highlights
- Converts the Schrödinger equation into an **initial value problem (IVP)** rather than a boundary value problem (BVP).
- Evaluates **phase shifts** by comparing computed wavefunctions with asymptotic Bessel functions.
- Auto-determines the stopping criteria by analyzing potential decay and asymptotic behavior.

## System of Units
QRONUS employs **Atomic Units (A.U.)**, ensuring computational accuracy and suitability for scattering calculations.

## Results
QRONUS demonstrates high accuracy in elastic scattering differential cross-section calculations, closely matching **NIST online database results**, with errors minimized to a fraction of atomic units.

## Copyright Notice
This work is **protected under exclusive copyright by default** and falls under applicable intellectual property laws. Unauthorized reproduction, distribution, or modification of this code **without explicit permission** is strictly prohibited.
