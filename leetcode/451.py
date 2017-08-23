class Solution(object):
    def frequencySort(self, str):
        return "".join([char * times for char, times in collections.Counter(str).most_common()])