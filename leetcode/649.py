class Solution(object):
    def predictPartyVictory(self, senate):
        delta = 0
        while len(set(senate)) > 1:
            nsenate = ''
            for s in senate:
                if s == 'R':
                    if delta >= 0: nsenate += 'R'
                    delta += 1
                else:
                    if delta <= 0: nsenate += 'D'
                    delta -= 1
            senate = nsenate
        return {'D' : 'Dire', 'R' : 'Radiant'}[senate[0]]