from r_extmember import Spam

s = Spam(42, 1.5, 88)

print s.tons
print s.tastiness
print s.get_temperature()
s.tons = 37
print s.tons
try:
	s.tastiness = 2.3
except Exception, e:
	print e
try:
	print s.temperature
except Exception, e:
	print e
