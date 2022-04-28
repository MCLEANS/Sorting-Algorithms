import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

log_file = "../data/log_file.csv"
try:
    df = pd.read_csv(log_file)
    df.columns = ['time','speed']
    utc_time = [str(x) for x in df['time']]
    speed = np.array(df['speed'])
    plt.plot(utc_time,speed, label = "speed curve")
    ax = plt.gca()
    ax.set_xticks(ax.get_xticks()[::20])
    plt.title("GRAPH OF SPEED AGAINST TIME")
    plt.xlabel("UTC Time (hrs)")
    plt.ylabel("Speed (Km/h)")
    plt.xticks(rotation = 90) 
    plt.grid()
    plt.gcf().subplots_adjust(bottom=0.2)
    plt.legend()
    plt.savefig("visual_plot.png", dpi=500)

except FileNotFoundError:
    print("File {} Not Found".format(log_file))