// September 1st, 2017 
// This won't work for specific case such as
// [121, 12] , this code will have result of 12112 rather then 12121
// but this is the good practice of String, char, int and all kind of basic function in Java
class Solution {
    public String largestNumber(int[] nums) {
        int digit, deci = 10;
		int size = nums.length;
		for(digit = 0; digit <= deci; digit++){
			for(int i =0; i < size; i ++){
				// iterate through each number
				int pivot = getDigit(digit,nums[i]);
				
				//Selection sort
				int max = nums[i],min_digit = pivot, index = i;
				for(int j = i; j < size; j++){
					int stage = getDigit(digit, nums[j]);
					if(stage > min_digit){
						index = j;
						min_digit = stage;
						max = nums[j];
					}
				}
				// exchange pivot with min
				nums[index] = nums[i];
				nums[i] = max;
			}
		}
		
		String s = "";
		for(int i = 0; i < size; i++){
			s = s + String.valueOf(nums[i]);
		}
        return s;
    }
    
    private int getDigit(int digitPlace, int target){
		if(target >= Math.pow(10,digitPlace)){
			return Character.getNumericValue(String.valueOf(target).charAt(digitPlace));
		}else{
            String number = Integer.toString(target);
			return Integer.parseInt(number.substring(0,1)); 
		}
	}
}