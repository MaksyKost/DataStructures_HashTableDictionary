import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

# Dane wejściowe
sizes = np.array([2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000]).reshape(-1, 1)

# Czas wyszukiwania dla każdej struktury danych

#dlist_times = np.array([0.501, 2.049, 4.562, 7.983, 12.106, 16.894, 22.223, 28.053, 34.284, 40.820])
#array_times = np.array([0.431, 1.956, 4.324, 7.251, 10.617, 14.368, 18.420, 22.712, 27.341, 32.112])

#dlist_times = np.array([0.499, 1.114, 1.764, 2.467, 3.196, 3.944, 4.703, 5.455, 6.235, 6.978])
#array_times = np.array([0.253, 0.576, 0.942, 1.316, 1.742, 2.214, 2.699, 3.183, 3.715, 4.221])

dlist_times = np.array([0.182, 0.354, 0.550, 0.703, 0.882, 1.108, 1.279, 1.445, 1.614, 1.786])
array_times = np.array([0.535, 1.999, 4.248, 7.211, 10.811, 14.983, 19.679, 24.861, 30.528, 36.485])


# Modele regresji
reg_array = LinearRegression().fit(sizes, array_times)
reg_dlist = LinearRegression().fit(sizes, dlist_times)

# Przewidywane wartości
sizes_flat = sizes.flatten()
pred_array = reg_array.predict(sizes)
pred_dlist = reg_dlist.predict(sizes)

# Funkcja do rysowania wykresów
def plot_with_fit(x, y, y_pred, title, label, color):
    plt.figure(figsize=(8, 5))
    plt.scatter(x, y, color=color, label=f'Czas ({label})', marker='o')
    plt.plot(x, y_pred, color='black', linestyle='--', label='Dopasowanie liniowe')
    plt.title(title)
    plt.xlabel('Rozmiar struktury danych')
    plt.ylabel('Czas [ms]')
    plt.grid(True, linestyle='--', alpha=0.6)
    plt.legend()
    plt.tight_layout()
    plt.show()

# Rysowanie wykresów
plot_with_fit(sizes_flat, array_times, pred_array, '', 'remove', 'blue')
plot_with_fit(sizes_flat, dlist_times, pred_dlist, '', 'insert', 'green')
