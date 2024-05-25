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
