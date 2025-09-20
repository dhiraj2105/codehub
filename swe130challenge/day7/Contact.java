
/*
 * The Contact class represents a single contact with name and phoneNumber.
 * It demonstrates encapsulation by keeping fields private and providing getter-setters/
 */
public class Contact {
    private String name;
    private String phoneNumber;

    // constructor
    public Contact(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    public String getname() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Phone: " + phoneNumber;
    }
}
