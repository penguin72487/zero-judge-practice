# Re-run the corrected code to find the optimal n and max value for Sn

# Define the initial conditions and parameters for the corrected calculation
S0 = 220
ratio = 69 / 100
Fee = 0.06
slip = 1.16/100
n = 365  # Assuming this was the intended maximum range for n

max_value = S0
optimal_n = 0

# Calculate Sn for increasing values of n until the maximum value is found
for i in range(1, n + 1):
    Sn = S0
    for j in range(1, i + 1):
        Sn = Sn * (1 + ratio*(1-slip) / i) - Fee
    if Sn > max_value:
        max_value = Sn
        optimal_n = i



print(optimal_n, max_value)
print(365/optimal_n)
