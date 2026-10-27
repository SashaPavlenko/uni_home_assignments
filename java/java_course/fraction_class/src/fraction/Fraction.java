package fraction;

public class Fraction {
    private int numerator = 0;
    private int denominator = 1;
    private boolean sign = true;
    
    Fraction(int numerator) {
        this.numerator = numerator;
        this.denominator = 1;
    }
    
    Fraction(int numerator, int denominator){
        this.numerator = numerator;
        this.denominator = denominator;
        
    }
    
    public void multiply(Fraction f) {
        numerator *= f.numerator;
        denominator *= f.denominator;
    }
        
}
