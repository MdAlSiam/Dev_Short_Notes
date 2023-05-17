import requests
import time

# Get the website URL from the user
website_url = input("Enter the website URL: ")

# Get the number of times the website should be visited from the user
number_of_visits = int(input("Enter the number of times the website should be visited: "))

# Start a loop that will visit the website the specified number of times
for i in range(number_of_visits):

    # Make a request to the website
    response = requests.get(website_url)

    # Check if the request was successful
    if response.status_code == 200:
        print("The website was visited successfully.")
    else:
        print("The website could not be visited.")

    # Wait for the specified interval before making the next request
    time.sleep(10)