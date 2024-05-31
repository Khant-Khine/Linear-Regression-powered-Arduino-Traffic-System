# Linear-Regression-powered-Arduino-Traffic-System
This project aims to help reduce the number of traffic intersection accidents, through discouraging drivers from attempting last minute crossings at the yellow light. This project is split into three components:
<ol>
<li>
Training Data
</li>
<li>
Software
</li>
<li>
Hardware
</li>
</ol>
The training data will be filled with information on what constitutes a dangerous speed at the last moments of the yellow light. This data will be analyzed through linear regression to return a decision on an action to be carried out. The linear regression is performed within a Python program that analyzes the data from the file mentioned above. If a vehicle is detected to be traveling at a dangerous speed when the yellow light is about to end, a yellow light extension is enabled to allow for safe passage of the speeding vehicle as well as preventing the other side from crossing, thus preventing collisions. An Arduino circuit will be constructed to simulate a traffic routine, while displaying the program's effects on the traffic routine. Arduino was selected as the hardware platform because of its modularity and open source nature, allowing for future additions and improvements to this project, as well as enabling community involvement in software reviews and updates.

## Programming languages and platforms used
<ul>
<li>
Arduino IDE
</li>
<li>
Python  
</li>
</ul>

## How to install and run
<ol>
  <li>
    First, we will start off by purchasing the hardware components required in this project. The following items are to be used within this project, and links for purchase are provided.
    <ul>
      <li>
        <a href="https://www.amazon.com/ATmega328P-Arduino-Compatible-Arduino-Voltage-Compatible/dp/B0CNH9D8VJ/ref=sr_1_5?crid=301KQH9GG8JPD&dib=eyJ2IjoiMSJ9.MazmhFfn-DF8W5oyX_S-tMmyamo23ZnK5izmXEoY4SOfPqgwi8JSG4-FEPokno20LZv03zfQbFBrypHp7Um6U6mwDdOrOkMl2Ac6f2FPei99js0rVjgCa9FqnsxgtiAH-d4-L6BTfAUsJKq2F09z6IARVX2FcwoUSJo4dWlLtuxf32HjaWEx9zM3BN8psAVWZdx-PVEN9n_1cSUszzuojIrZqbJ-CraA9VLVmE6XM4t5oxSxRSavowwq8OhPbTkqh5dMokyiav3mesFF8fyUeoeh_tgq3AEitnEVD0ZZE2k.t2Hit73Zz3B-NPn_m05W4vKW-4jQRrRoKmpqbqZZaUw&dib_tag=se&keywords=arduino+uno+r3&qid=1716607435&s=electronics&sprefix=arduino+uno+r3%2Celectronics%2C217&sr=1-5">Arduino Uno</a>
      </li>
      <li>
        <a href="https://www.amazon.com/DEYUE-breadboard-Set-Prototype-Board/dp/B07LFD4LT6/ref=sr_1_3?crid=24ZV8GYXJCE5X&dib=eyJ2IjoiMSJ9.0XjhQpvsxVGvVwki4XDjTdziZtM7NtJzJKlf3z7Il1QmzRSz_j9yeoNHP2hXpFnmgeCc4MOwWlHv2ezk8d1UJuR5fH1-r-5-Q2f62ZiWHZz8mkZT27zlzVrO9uzGhQ1HCKFJpLOUruIqnFm-ZAPDkOTnRmZCbFvzN_L5GNxmUIXYXelAoI3YuUMhzgI9-B3D3ZKmKurZ67hhL97GEwuQRUQbhUPHR__oj6UCzMjmDsM.jK8x94-HZKVr9tUCIAAljNYZijbNrj7ZmfLcmO_7AGg&dib_tag=se&keywords=breadboard&qid=1717022815&sprefix=breadboard%2Caps%2C105&sr=8-3">Breadboard</a>
      </li>
      <li>
        <a href="https://www.amazon.com/MCIGICM-Circuit-Assorted-Science-Experiment/dp/B07PG84V17/ref=sr_1_3?dib=eyJ2IjoiMSJ9.b7ufUOS8MkW6Hm7aEmixGNbvN1ezApUaqucbPDD4HeBIzkA25YUIp5ZJJtzq8H9E9bTt3kPL8sVLBKUkVO8OdIYjwy73Q2Wu_cA3pTsKAZRSkMsvVRVd72OEFWMeK2EZiuMQ9TjT3A6DC63Unc4hQ5gkXPYISbbpKzKYiwy_E9yCHqWiUMTyWRbTZzIWk0hSPkRury-qObKYuiLQHOty-nGZwNI6WtHQo45LcWqt0Lo.UoAm4TrwEVEGWTLQbBMnPAa8sU4yNN58YdN0Nq0zAt0&dib_tag=se&keywords=led%2Barduino&qid=1716771681&sr=8-3&th=1">LEDs</a>
      </li>
      <li>
        <a href="https://www.amazon.com/Resistors-Assortment-Tolerance-Excellently-Breadboards/dp/B07D2Z45CG/ref=sr_1_3?crid=HVZ7MF2HYZ48&dib=eyJ2IjoiMSJ9.NkKUS8ov2i3GlBJLPLMMHxZ9Q0psaPXkJQdAAbDEu3Xvqn_2_5a1KLkVUcKNSCmVywiPR-9bcmGI-QbR7JHrIL7XKWFfNHluUqIr_zBHzUfCTM0l98KgN1h06mLgwMzPJchhbsJVoplyDk89IboM16xaVGHA1Dgea768HupZKXv9xmN1flPdSTRq6irSuyUdk259XjwRJuomsplNw2XdI8ESU6JF73ythoQHTA_HIr4._iicuXApAkztkvDy8owN4ImVy5ZUfFEpMKf-psij17g&dib_tag=se&keywords=arduino+resistors&qid=1716771842&sprefix=arduino+resistors%2Caps%2C109&sr=8-3">Resistors</a>
      </li>
      <li>
        <a href="https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=sr_1_3?crid=22L7ZG39IF9BB&dib=eyJ2IjoiMSJ9.tjHxIQLJsk16_0YVtUGN6aqwkJL6hCuidHoQKI-5vjtAbcUgEXc1QlyA-u9wgMq1wuzWBSEktVpkES_WXYoLPKRPeoMZ_ocMmyMZL_sAF84FFbZk8OarpZdLajR7eha1KoReeCWebPvBNv8hagoolVYMz6imh2GBju0rQ8QLSeyEGFQE3olMW6EqxuKdR_hIx4MhjoehNI22LmQq7FYTAxrBJJ_QlHhBXnhGHD9UCZOjtee6UPo-YzjBOFwrYXAnypPAtpI1hQSLdbE84a0u6ISHnYanqEkiDLU1S_WCl_k.jAdH5ExcokVXXo2SExEjZaqlWRyIHHUh5MycKXGlN3M&dib_tag=se&keywords=arduino+jumper+wires&qid=1716771996&s=electronics&sprefix=arduino+jumper+wires%2Celectronics%2C103&sr=1-3">Jumper Wires</a>
      </li>
    </ul>
  </li>
</ol>
These links will provide you with ample components to develop your own Arduino projects in the future. However, if you would only like to purchase only necessary components, I have provided two links which contains all the components <a href="https://www.amazon.com/ELEGOO-Starter-Tutorial-Compatible-Official/dp/B01DGD2GAO/ref=sr_1_6?crid=3HA2POT1HH3K8&dib=eyJ2IjoiMSJ9.3XHFL9OmzekFEUMRY5K2AiEfMKfKczWMZNuDBQjgbkdbusYGfNhLUab0ubEPpN2CLsRSw-cRDL4_KULt7OIQZDNIjd2qcE4-ZQxq7dEa6P8d0hv6g6nh9UwNwThDrS_mpLJVi3FaPxS7abQoR5vm1FJrcUsBoiRS7KjxF8tXK1E_BOcy5YTbJ7aT51VNsrbJSMBVe9jn7s0tVkjgiJHSKgTGALyGoVERbPqtfToR94I.3bnUYphXJdK9_Z7VPmYoaUG20kAgZY4alalE7r7ELxU&dib_tag=se&keywords=arduino+set&qid=1717023169&sprefix=arduino+set%2Caps%2C94&sr=8-6">here,</a> and <a href="https://www.amazon.com/WWZMDiB-HC-SR04-Ultrasonic-Distance-Measuring/dp/B0B1MJJLJP/ref=sr_1_4?crid=CM0CMPV2T2XB&dib=eyJ2IjoiMSJ9.E2SIkElJhtFWCJCHL5Q6YwwtxyRhETnroFHfs4vAAJODiudL5DQ5XWsGLO8SrIjE0JxzpGDVqTVQ1FoTTNDt5ypj1E1RjN3u0jCxepAAUDaZ2wISH9mwi1WyMutVsjsnBkZaNNhML0sVAGAq60QrYva7RS5xVlqkWqdUxB8uvGKKBdLYVTm4wGW1LOG6YB8zPKREUQlLvSuZoGjnAnR7OBhxXAZBVeKiLwFI33_dLE07kxqh5c5ikTs7o7z9yJG2mIEZUlMC1GL_3C4ON95tK140rRLV9TB0aALvfzprx7A.ZeX_KoRGiA3zarfbFBxXYorY068Lf4EB-m2S0UGTgpA&dib_tag=se&keywords=arduino+ultrasonic&qid=1717023250&sprefix=%2Caps%2C116&sr=8-4">here.</a><br><br>

Software Installations:
Python IDLE
Arduino IDE

## Hardware Assembly
<ol>
  <h3><li>Circuit Design</li></h3>
     <img src="https://github.com/Khant-Khine/Linear-Regression-powered-Arduino-Traffic-System/assets/155600182/3e85be32-5e0f-470b-984e-01f715013973"><br>
  The above picture is how the circuit for our project will be constructed. On observing the image, we should be able to analyze the number and types of items needed for this circuit. The items required are:
  <ul>
    <li>1 Arduino Uno R3</li>
    <li>1 Breadboard</li>
    <li>2 Ultrasonic Sensors</li>
    <li>10 LEDs (2 Red, 2 Yellow, 2 Green, 2 White, 2 Blue)</li>
    <li>10 1kΩ Resistors</li>
    <li>18 Jumper Wires</li>
  </ul>
  <br>
  We will be simulating a traffic intersection, one traffic light for traffic from East to West, and one traffic light for traffic from North to South. Now, we shall begin assembling the circuit.<br>
  <h3><li>Assembling the circuit</li></h3>
  We will start off by connecting the ultrasonic sensors to the Arduino Uno R3.
  <img src="https://github.com/Khant-Khine/Linear-Regression-powered-Arduino-Traffic-System/assets/155600182/19e2467f-3d45-415c-b969-442d8539af59">
  <br>
  The ultrasonic sensor has 4 connections. The pin labeled Vcc will be the 5V power supply for the ultrasonic function. The next two pins, labeled Trig and Echo, will be connected to digital pins on the Arduino Uno R3. 
</ol>

## Uploading the Arduino code to Hardware
<ol>
  <li>Verifying the Program</li>
  <li>Uploading the Program</li>
</ol>

## How to operate the Python code
Run on IDLE

## Streamlit on Python
Display visualizer


