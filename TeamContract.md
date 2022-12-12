# CS225_Final_Project
# Team Contract

## Communication
1. **Team Meetings**    
The team will plan on having 1-2 hour meetings every 2-3 days of the week leading up till the final deadline. Meetings will be conducted over Discord since it has good connectivity and communication tools. In terms of meeting notes, we will stay accountable by always discussing project progress, goals for the future, and things we need to work on as a team to reach our development goals.

2. **Assistance**

    If teammates want to be able to contact one another they can connect through phone numbers or Discord. In terms of response times, we will make sure that we respond to one another within 1-2 hours so that we keep a steady pace and at the latest respond after our classes of the day.

3. **Respect** 

    A way of keeping all teammates engaged and open to expressing their ideas will be bolstering communication and peer review of ideas. Ideally, teammates can contact the group chat for the opinion of other members or perhaps there can be some sort of idea board which members can contribute to during the week and then the board will be discussed at the meetings.

## Collaboration

4. **Work Distribution** 

    During our weekly meetings, we will assess and create goals for the week for things we want to accomplish on the project. Then by talking to each other and understanding what each member feels comfortable working on, we will split up the work accordingly and make sure everyone understands their responsibilities. We will address any unforeseen issues/extra work in these meetings and determine who will have to do what so that we can get through that work. We aim to have everyone complete equal amounts of work on the final deliverable so we will keep track of everyone’s work during the meetings to get a sense of how we are progressing and how much work has been completed.

5. **Time Commitment** 

    Along with our two 1-2 hour weekly meetings, we suspect that we will have to spend around 5-6 hours a week working on our share of the project. This will likely vary depending on the amount of total work necessary to complete individual deliverables, but we will plan to spend that amount of time each week on the project(a ceiling time). Members will have to communicate with each other if any time conflicts occur for a scheduled weekly meeting and then work around each other's schedule to find a different time that works. For individual work, everyone is free to work on the project whenever best suited for them over the course of the week. As long as we are making progress on the final project as planned, individual work is not on a strict time schedule of having to be completed on a certain day. 

6. **Conflict Resolution** 
    At the start of our meetings, we will address any concerns that any of the group members have. If someone is habitually late, we will attempt to figure out why and reschedule our meetings if necessary to prevent any time conflicts. We will check in on whether expected tasks were completed during the meeting. If they were not completed, we will pry into why it wasn’t completed and make a plan to have it completed. If there is any disagreement between members, we will identify where the disagreement stems from and try to resolve the issue ourselves during meeting times.

## Signatures
Shaarav Rotiwar: rotiwar2

Shreyas Khati: sskhati2

Aadarsh Hegde: ahegd2

Krushank Bayyapu: kbayy2


# Final Project Proposal
## Leading Question 

The end goal of our project is to learn more about the applications of optimizations in real-world situations - in this case figuring out how we can optimize the route between two airports. The primary goal would be to find the shortest route from the input airport to the target airport, and the secondary goal would be to find the most popular airport with a list of the top n closest airports that the user specifies. We will be using Dijkstra's algorithm to determine the shortest path between 2 airports, and we will be using the PageRank algorithm to determine the most important airport.

## Dataset Acquisition

### Data Format

In regards to the data format, our dataset is sourced from OurAirports, which is linked at https://openflights.org/data.html. Additionally, the OpenFlights Routes Database contains 67,663 routes between 3,321 airports on 548 airlines spanning the globe. The data is displayed as a .dat format, with comma-separated values, and we will be focusing on a subset of the data regarding the airports in the US region. Since we are able to see the country that each airport is located in, we can use this to filter out the airports from other countries. The subset will contain only airports that are located in the US region and have connections/routes to other airports located in the US.

### Data Correction

Since the dataset we will be using is a CSV (.dat) file, we will be reading in the file using a stringstream. Once we have fully loaded the dataset into a map, we will then find the average of the distances. If the numeric column has a value that is extremely large/negative or does not exist, then it will be replaced with that average value to ensure we do not have outliers. If one of the string locations cannot be found (for example it is missing/NA), then the entire entry will be removed from the map.

### Data Storage

We will be using a map that has the key as the airport and the value will be a vector that will hold the rest of the values as strings.  The total storage costs for the dataset would be O(N), where N would be the number of airports included in the dataset.

## Algorithm 

We will be implementing Dijkstra's algorithm in order to find the shortest/optimal route from the input location to the destination. The input to the algorithm would be both the input airport as well the desired destination airport. We would not need to change our stored dataset, as we will be implementing Dijkstra's algorithm using the original map from the dataset we read it into. The output would be a vector that contains the stops from the input to the destination. If the vector is empty, one element will be pushed back stating it is a direct flight. A target goal for the Big O efficiency for Dijkstra's algorithm would be O(Elog(V)), where V would be the number of airports and E would be the number of edges between the airports. 

We will also be implementing the PageRank algorithm in order to determine the busiest airport based on how many incoming/outbound flights there are as well as how many airports are connected to the target airport. The algorithm would not need any inputs, however the output would be a map where the key is the airport and the value is a vector containing the airports that are connected to the target airport. A target goal for the Big O efficiency for the PageRank algorithm would be O(E+V) where E is the number of edges/routes between airports and V is the number of airports.

For the purposes of our final project, the two graph data algorithms we will implement are Dijkstra’s algorithm and the PageRank algorithm. Dijkstra’s algorithm will be used for finding the shortest number of stops between airports while the PageRank algorithm will be used to determine the most popular (most visited) airports. We will be implementing the BFS traversal for our graph traversal.

## Timeline

Data processing and cleaning: Starting on Nov 7th until Nov 12th

Set up the graph and map data structures: Starting on Nov 14th - Nov 18th **(MID PROJECT CHECKIN)**

Complete and test Dijkstra’s algorithm for finding shortest path: Starting on Nov 19th - Nov 26th

Complete and test PageRank Algorithm for finding most important airport: Starting on Nov 26th - Dec 2nd (could be done earlier if work is split up)

Debugging functions, verifying and testing all code: Dec 3rd - Dec 5th

Concluding presentation and code overview: Dec 5th - Dec 8th
