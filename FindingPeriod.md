
# Museum  Visitor

The algorithm find the window of time when the maximum people are in the museum. A list of time value pairs that indicate the arrival and leave timings of visitors.

## Code Steps :

### Read Input:

Read the visiting hours from the input file. The entering and leaving times are separated by commas on each line.

### Visitor Sorting:

Arrange the visitor list according to when they checked in. This guarantees that visitors are handled in the order that they arrive.

### Loop Using Guests:

- We have created variables to record the maximum number of visitors, the number of visitors, and the beginning and ending times of the most-visited period.

-  We will iterate over the visitors' sorted list again.

- Determine if there are any overlaps in the intervals between each visitor and the ones after them.

- If a new maximum num of visitor is discovered, update the maximum number of visits and keep track of the number of overlapping intervals.

- Adjust the start and end time of the most visited period in accordance with the number of visitors.

### Result of Output:

Print the start and end times of the most visited time period, as well as the number of visitors.




