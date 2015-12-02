from ubidots import ApiClient
import random

#Create an "API" object
api = ApiClient("7fj39fk3044045k89fbh34rsd9823jkfs8323")

#Create a "Variable" object
test_variable = api.get_variable("521d792df91b2816f35c8587")

#Here is where you usually put the code to capture the data, either through your GPIO pins or as a calculation.We'll simply put a random value here:
test_value = random.randint(1,100)

#Write the value to your variable in Ubidots
test_variable.save_value({'value':test_value})
