class Solution(object):
    def validIPAddress(self, IP):
        IPV4 = IP.split('.')
        if len(IPV4) == 4 :
            for val in IPV4 :
                if not val : return "Neither"
                if val[0] == '-' or val[0] == '0'and len(val) > 1 : return "Neither"
                try : 
                    val = int(val)
                    if val < 0 or val > 255 : return "Neither"
                except : return "Neither"
            return "IPv4"
        IPV6 = IP.split(':')
        if len(IPV6) == 8 : 
            for val in IPV6 :
                if not val : return "Neither"
                if val[0] == '-' or len(val) > 4  : return "Neither"
                try : int(val, 16)
                except : return "Neither"
            return "IPv6"
        return "Neither" 