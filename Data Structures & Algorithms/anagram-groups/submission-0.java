class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> freq = new HashMap<>();
        for(String s : strs)
        {
            String s1 = s;
            char tempArray[] = s1.toCharArray();
            Arrays.sort(tempArray);
            s1 = new String(tempArray);
            // System.out.println(s + " " +s1);
            if(freq.containsKey(s1))
            {
                freq.get(s1).add(s);
            }
            else
            {
                List<String> li = new ArrayList<>();
                li.add(s);
                freq.put(s1, li);
            }
        }
        List<List<String>> li = new ArrayList<>();
        for (Map.Entry<String, List<String>> e : freq.entrySet()) {
            li.add(e.getValue());
        }
        return li;
    }
}
