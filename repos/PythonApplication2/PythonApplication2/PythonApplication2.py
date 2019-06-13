import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import pymysql
# Read data from csv files
# df = pd.read_csv('E://CapacityData/test-data-set/MeishanRenshou.csv')
# Read data from mysql, including downstream_userplane_flux, max_rrc_connection_number.
conn = pymysql.connect(user='root', passwd='root123',
host='localhost', db='capacitypredict', charset='utf8')
cur = conn.cursor()
cur.execute("select concat(netelement,cellid)as id , max_rrc_connection_number from table" "where DATE_FORMAT(starttime, '%Y-%m-%d')>='2016-11-01' "
 "and DATE_FORMAT(starttime, '%Y-%m-%d')<='2016-12-07'"
"order by id ")
sqlData = cur.fetchall()
cur.close()
conn.close()
print(sqlData)
originalId = sqlData[0][0]
data = []
SRMSE = []; SMAPE = []; SMSE = []; fPredictData = []; fOriginalData =[]
lead = 7 # Define predict steps
# Define alpha, which used to adjust weights
alpha = 0.3
for d in sqlData:
 print(d)
 if d[0] == originalId:
  data.append(float(d[1]))
 else:
 # Testing the data's length
if len(data) == 37:
 # In this section, we calculate the one-ES 
S1 = []
firstS1 = 0
for t in range(0, len(data)):
  if t == 0:
   for n in range(0, 3):
    print(data)
firstS1 += float(data[n])
S1.append(firstS1/3)
else:
   S1_diff = alpha*data[t-1] + (1-alpha)*S1[t-1]
   S1.append(S1_diff)
   print(S1)


 # In the next part, we compute the two—ES
 S2 = []
 firstS2 = 0
 for s in range(0, len(S1)):
  if s == 0:
    for m in range(0, 3):
        firstS2 += float(S1[m])
        S2.append(firstS2/3)
    else:
        S2_diff = alpha*S1[s-1] + (1-alpha)*S2[s-1]
        S2.append(S2_diff)
 print(S2[1:10]) # Output several S2 data


 # Next, calculate the parameters slope & intercept
 slope = 0
 intercept = 0
 predictValues = []
 for i in range(0, len(data)):
  intercept = 2*S1[i] - S2[i]
 slope = (alpha/(1-alpha))*(S1[i]-S2[i])
 predict = intercept + slope*lead
 predictValues.append(abs(predict))

 # Define how many days or weeks, we want to predict: K_count
 K_count = 7
 # original data
 originalData = data[len(data)-K_count:len(data)]
 print(len(originalData))
 # predicted values. I discard the last value, because it is the predicted value for t+1
 predictData = predictValues[len(predictValues) - lead - K_count:len(predictValues) - lead]
 print(len(predictData))
 # Computing the indicators like RMSE, MAPE //(import math math.sqrt)
 MSE = sum((np.array(originalData)-predictData)**2)/K_count
 MAPE = sum(abs(np.array(originalData)-predictData)/(np.array(originalData)+0.001))/K_count
 print("the model's RMSE is: ", MSE)
 print("the model's MAPE is: ", MAPE)
 SMSE.append(MSE)
 SMAPE.append(MAPE)
 # Resetting the var: data
 data = []
 # Alter the originalId
 print(d)
 originalId = d[0]
 data.append(float(d[1]))
 # Storing the predicted data and
 fOriginalData.append(originalData)
  fPredictData.append(predictData)
  else:
  data = []
  originalId = d[0]
  data.append(float(d[1]))


# Print the final values of error indicators
 meanMse = sum(SMSE) / len(SMSE)
 print("This district's mean mse is: ", meanMse)