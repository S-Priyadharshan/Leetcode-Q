class Bank {
    long[] balance;
    long size;

    public Bank(long[] balance) {
        this.balance=balance.clone();    
        this.size=balance.length;
    }
    
    public boolean transfer(int account1, int account2, long money) {
        account1--;
        account2--;
        if((account1>=0 && account1<size)&&(account2>=0 && account2<size)){
            if(balance[account1]<money){
                return false;
            }else{
                balance[account1]-=money;
                balance[account2]+=money;
                return true;
            }
        }else{
            return false;
        }
    }
    
    public boolean deposit(int account, long money) {
        account--;
        if(account>=0 && account<size){
            balance[account]+=money;
            return true;
        }else{
            return false;
        }
    }
    
    public boolean withdraw(int account, long money) {
        account--;
        if(account>=0 && account<size){
            if(balance[account]<money){
                return false;
            }else{
                balance[account]-=money;
                return true;
            }
        }else{
            return false;
        }
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */