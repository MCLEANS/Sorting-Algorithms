## How to compile 
Compilation requires prior installation of *gcc* and *make* tools.

To compile the *.c file use the command "make all" command.

To run the compiled binary use the command "make run".

Running the program generates an output file "log_file.csv" that contains time (utc format) and speed data.

## Output file
The output file is located in the /data folder and is named "log_file.csv"

## Visualization.
The data is visualized using a python program located in the "/visualization" folder. 

When the file "visualize.py" is run using a python interprator it reads the logged data from "log_file.csv" and generates a plot image "visual_plot.png".

Running the python file requires the following python modules:

    - pandas
    - numpy
    - matplotlib