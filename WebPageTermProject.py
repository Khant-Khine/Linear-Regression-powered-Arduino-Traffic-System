#Name: Khant Khine
#Course: CS-470
#Brief: Display for how many triggered speeds and latest speed recorded.

import streamlit as st
import pandas as pd
import time

def load_data(file_path):
    try:
        df = pd.read_csv(file_path)
        return df
    except Exception as e:
        st.error(f"Error: {e}")
        return None

def main():
    st.title('AI Smart Traffic Light Data Visualizer')
    
    file_path = 'TrafficLightData.csv'
    accidents_avoided_placeholder = st.empty()
    last_speed_placeholder = st.empty()
    
    if file_path is not None:
        df = load_data(file_path)
        if df is not None:
            # Counting 'Action to take' with value 'Yes'
            while True:
                df = load_data(file_path)
                if df is not None:
                    accidents_avoided_count = df[df['Action to take'] == 'Yes']['Action to take'].count()
                    accidents_avoided_placeholder.write(f"<h2>Number of Accidents Avoided: {accidents_avoided_count}</h2>", unsafe_allow_html=True)

                    # Get the last recorded speed
                    if not df.empty:
                        last_speed = df.iloc[-1]['Car Speed']
                        last_speed_placeholder.write(f"<h2>Last Recorded Speed: {last_speed} m/s</h2>", unsafe_allow_html=True)

                time.sleep(5)

if __name__ == "__main__":
    main()
