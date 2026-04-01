class Solution {
    public boolean isAnagram(String s, String t) {
        int arr[] = new int[26];
        int n = s.length();
        for(int i=0;i<n;i++)
            arr[(int)(s.charAt(i) - 'a')]++;
        n = t.length();
        for(int i=0;i<n;i++)
            arr[(int)(t.charAt(i) - 'a')]--;
        for(int i=0;i<26;i++) if(arr[i] > 0 || arr[i] < 0) return false;
        return true;
    }
}
