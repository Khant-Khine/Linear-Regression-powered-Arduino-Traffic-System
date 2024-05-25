#Name: Khant Khine
#Course: CS-470
#Brief: Logistic Regressor model for making decisions from Arduino serial port
#       and adding results back to training data file.

import serial
import numpy as np
import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import LabelEncoder
import pickle
import time

# Input file with data
input_file = 'TrafficLightData.csv'

# Read data using pandas
data = pd.read_csv(input_file)

# Separate data
X = data['Car Speed'].values.reshape(-1, 1) 
y = data['Action to take']

# Convert string to numerical number using LabelEncoder
encoder = LabelEncoder()
y_encoded = encoder.fit_transform(y)

# Create logistic regressor
classifier = LogisticRegression()

# Train the model using the entire dataset
classifier.fit(X, y_encoded)

# Save the trained model for faster runtime
with open('logistic_regression_model.pkl', 'wb') as f:
    pickle.dump(classifier, f)

# Open serial connection
ser = serial.Serial('COM4', 9600)
ser.timeout = 1

times = 0  # Loop counter set to 0.
time.sleep(5) 
while True:
    times += 1  # Loop counter is increased every loop.
    
    # Print loop number
    print("Loop", times)
    
    # Receive data from Arduino
    time.sleep(5) 
    new_car_speed = ser.readline().decode('ascii').strip()  # Decode bytes from Arduino to string and remove whitespace
    print("Received data from Arduino:", new_car_speed)

    try:
        # Convert received data from Arduino to float
        new_car_speed_float = float(new_car_speed)
        
        # Predict the action to be taken for the new car speed
        predicted_action = classifier.predict(np.array([[new_car_speed_float]]).reshape(-1, 1))
        
        # Display and send response back to Arduino
        print("Predicted Action to Take for Car Speed", new_car_speed_float, ":", predicted_action)
        ser.write(predicted_action)  # Send decision back to Arduino through Serial port
        print("Data sent from Python to Arduino: ", predicted_action)

        # Add new input data and its result to the originial training csv file
        predicted_action_label = encoder.inverse_transform(predicted_action)
        predicted_action_label[predicted_action_label == '1'] = 'yes'
        predicted_action_label[predicted_action_label == '0'] = 'no'
        new_data = pd.DataFrame({'No.': [len(data) + 1], 'Car Speed': [new_car_speed], 'Action to take': [predicted_action_label[0]]})
        data = pd.concat([data, new_data], ignore_index=True)

        # Write the updated data back to the CSV file
        data.to_csv('TrafficLightData.csv', index=False)
    
    except ValueError:
        print("Error: Received data is not a valid float")
    print()
    
    # Short delay for serial buffer
    time.sleep(0.5)
