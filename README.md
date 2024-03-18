# AQI-Prediction-Rover
The AQI Prediction Rover is a robotic system designed for environmental monitoring and air quality prediction. Equipped with advanced sensors and machine learning capabilities, this rover collects real-time data, predicts the Air Quality Index (AQI), and provides insights into environmental conditions.
# Features:
1. Obstacle Detection: The rover features a radar system that detects obstacles in its path and autonomously navigates around them using servo motors and an ultrasonic sensor connected to an Arduino UNO.
2. Sensor Array: It is equipped with a variety of sensors including MQ-135, DHT, and optical dust sensors connected to a NodeMCU. These sensors capture environmental parameters such as air quality, temperature, humidity, and dust concentration.
3. Data Collection and Transmission: While in motion, the rover collects data from the sensors and transmits it to an IoT cloud platform via the NodeMCU. This ensures real-time monitoring and analysis of environmental conditions.
4. Dataset Creation: The collected data is stored and processed to create a dataset containing environmental parameters and corresponding AQI values. This dataset serves as the basis for training machine learning models.
5. AQI Prediction: Machine learning models are trained on the dataset to predict the AQI of the location based on the sensor readings. These predictions provide valuable insights into air quality and pollution levels.

# Repository Structure:
1. 'ObstacleAvoidanceBotCODE/': Contains Arduino code for obstacle detection and navigation.
2. 'DustPrediction/': Includes code for data collection of the gasses from the sensors.
3. 'smokeTemphum/': Includes the code for data collection from the DHT sensor.
4.  There are three different Machine learning Model Codes that contain scripts for dataset creation, model training, and AQI prediction.
5.  'Dataset Collected;/: Contains the dataset generated from sensor readings.
6.   Report for Industrial Training contains detailed documentation, circuit diagrams, and project reports.

#Usage:
1. Clone the repository to your local machine.
2. Upload the Arduino and NodeMCU code to the respective microcontrollers.
3. Follow the documentation for circuit connections and setup.
4. Run the machine learning scripts to train models and predict AQI values.
5. Explore the dataset and experiment with different algorithms for prediction.

#Contributions:
Contributions to the project are welcome! Feel free to submit pull requests for bug fixes, enhancements, or new features.
