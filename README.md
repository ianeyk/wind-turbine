# wind-turbine
Working repo for summer research on the Just Energy Hub wind turbine design.

## GitHub Repo Index
* **Small_wind_turbine**
    * **3_phase_generator_buck_converter.plecs:** Main working PLECS model for the small turbine buck converter
    * **Frequency_analysis_buck_converter**
        * Contains four additional PLECS models which were used to run bode plots for designing the compensator circuit for the small wind turbine.
    * **Small_turbine_buck_converter_parameters**
        * **Buck_converter_parameters.ipynb:** Jupyter Notebook containing calculations for the inductor value and compensator circuit.
        * **Buck_converter_parameters.html:** Exported HTML of same Notebook
        * **Buck_converter_parameters.pdf:** Exported PDF of same Notebook
        * **Plecs_helper.py:** Library of helper functions used in the Notebook
    * **KiCAD:** Contains the schematic and layout for the small-scale buck converter PCB board which I designed and manufactured over the summer.
* **Large_wind_turbine**
    * **siemens_model_buck_converter_v1.plecs:** Main working PLECS model for the large turbine buck converter, including the 1FW3208-1EE model of the physical generator. The only things that are different between this model and the small_wind_turbine model are the inductor value, compensator values, and perhaps the input capacitance.
     * **1_kv_3phase_generator_buck_converter.plecs:** Older model without using the 1FW3208-1EE model.
    * **Frequency_analysis_buck_converter**
        * Contains four additional PLECS models which were used to run bode plots for designing the compensator circuit for the large wind turbine.
    * **Large_turbine_buck_converter_parameters**
        * **Buck_converter_parameters.ipynb:** Jupyter Notebook containing calculations for the inductor value and compensator circuit.
        * **Minimum_conversion_ratio.ipynb:** Jupyter Notebook containing calculations for the minimum switching time given a 1kV-12V buck converter voltage ratio. I concluded that this is perfectly feasible given a 10kHz switching frequency.
    * **KiCAD:** Folder containing duplicates of the small wind turbine KiCAD files. I was going to start with a copy and modify it, but I never got around to starting it.
    * **LTspice:** Contains a single LTspice model verifying that the bootstrap gate driver will work.
* **Generic_wind_turbine**
    * Earlier exploratory work which served as a template for the above analyses. It should probably be moved to the Archive folder.
* **Measurements_and_calculations**
    * **Battery_measurements**
        * **Battery_resistance.ipynb, .html, .pdf:** Jupyter Notebook analyzing a small set of data I took on our 12V marine batteries in the lab to quantify the internal resistance.
    * **Generator_internal_resistance**
        * **Internal_resistance.ipynb, .html, .pdf:** Jupyter Notebook and exported versions for calculating various parameters relating to the small test turbine, as well as speccing circuit components for the small buck converter. In addition to calculating the internal resistance of the small test generator based on oscilloscope data as the name implies, it also calculates such things as how much current the turbine can supply at safe rotation speeds, specs for the input capacitance value, slew rate to ensure the diff amps can respond fast enough, and resistor values for the indicator LEDs.
    * **Generator_volage**
        * **Generator_voltage.ipynb, .html, .pdf:** Jupyter Notebook plotting the results of putting the small test turbine in front of the wind tunnel. It calculates the frequency and voltage amplitude at various wind speeds.
    * **Large_turbine_power_predictions**
        * **Large_turbine_power_predictions.ipyny, .html, .pdf:** Jupyter Notebook and exported versions analyzing the power generation data from one of the Eastern Wind Power documents as well as a PLECS model for the generator and the anemometer data from Olin's campus. I recommend a cut-out wind speed of 12m/s for the large turbine.
* **Charge_controller_code**
    * **Platformio.ini:** Platformio project for code running on the Adafruit Feather Adalogger board attached to the small-scale buck converter PCB I designed and manufactured this summer.
    * **src/main.cpp:** Main code file containing Arduino language to be uploaded to the Feather.