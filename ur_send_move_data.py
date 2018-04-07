# Echo client program
import socket
import time
HOST = '158.42.206.10'    # The remote host
PORT = 30002              # The same port as used by the server
print 'Starting Program'
count = 0
while (count < 1):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((HOST, PORT))
	time.sleep(0.05)
	s.send ('set_digital_out(2,True)' + '\n')
	time.sleep(0.1)
	print '0.2 seconds are up already'
	s.send ('set_digital_out(7,True)' + '\n')
	time.sleep(10)
	s.send ('movej([-1.95, -1.58, 1.16, -1.15, -1.55, 1.18], a=1.0, v=0.1)' + '\n')
	time.sleep(10)

	s.send ('set_digital_out(4,True)' + '\n')
	time.sleep(1)
	s.send ('set_digital_out(4,False)' + '\n')
	time.sleep(1)

	s.send ('movej([-1.95, -1.66, 1.71, -1.62, -1.56, 1.19], a=1.0, v=0.1)' + '\n')
	time.sleep(10)

	s.send ('set_digital_out(4,True)' + '\n')
	time.sleep(1)
	s.send ('set_digital_out(4,False)' + '\n')
	time.sleep(1)

	s.send ('movej([-1.96, -1.53, 2.08, -2.12, -1.56, 1.19], a=1.0, v=0.1)' + '\n')
	time.sleep(10)
	
	s.send ('set_digital_out(4,True)' + '\n')
	time.sleep(1)
	s.send ('set_digital_out(4,False)' + '\n')
	time.sleep(1)

	s.send ('set_digital_out(2,False)' + '\n')
	time.sleep(0.05)
	print '0.2 seconds are up already'
	s.send ('set_digital_out(7,False)' + '\n')
	time.sleep(1)
	count = count + 1
print 'The count is:', count
time.sleep(1)
data = s.recv(1024)
s.close()
print ('Received', repr(data))
print 'Program finish'

# time.sleep(2)
# 	s.send ('movej([-0.5405182705025187, -2.350330184112267, -1.316631037266588, -2.2775736604458237, 3.3528323423665642, -1.2291967454894914], a=1.3962634015954636, v=1.0471975511965976)' + '\n')
# 	time.sleep(2)
# 	s.send ('movej([-0.7203210737806529, -1.82796919039503, -1.8248107684866093, -1.3401161163439792, 3.214294414832996, -0.2722986670990757], a=1.3962634015954636, v=1.0471975511965976)' + '\n')
# 	time.sleep(2)
# 	s.send ('movej([-0.5405182705025187, -2.350330184112267, -1.316631037266588, -2.2775736604458237, 3.3528323423665642, -1.2291967454894914], a=1.3962634015954636, v=1.0471975511965976)' + '\n')
# 	time.sleep(2)
# 	s.send ('movej([-0.720213311630304, -1.8280069071476523, -1.8247689994680725, -1.3396385689499288, 3.215063610324356, -0.27251695975573664], a=1.3962634015954636, v=1.0471975511965976)' + '\n')
# 	time.sleep(2)
# 	s.send ('movej([-0.540537125683036, -2.2018732555807086, -1.0986348160112505, -2.6437150406384227, 3.352864759694935, -1.2294883935868013], a=1.3962634015954636, v=1.0471975511965976)' + '\n')
# 	time.sleep(2)
# 	s.send ('movej([-0.5405182705025187, -2.350330184112267, -1.316631037266588, -2.2775736604458237, 3.3528323423665642, -1.2291967454894914], a=1.3962634015954636, v=1.0471975511965976)' + '\n')
# 	time.sleep(2)
# 	s.send ('movej([-0.7203210737806529, -1.570750000000000, -1.570750000000000, -1.3401161163439792, 3.2142944148329960, -0.2722986670990757], t=4.0000000000000000, r=0.0000000000000000)' + '\n')
# 	time.sleep(4)