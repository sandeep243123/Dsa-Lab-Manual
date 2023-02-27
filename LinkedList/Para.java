import java.util.*;
class node
{
    int data;
    node next;

}
class List
{
    public node moveL(node head)
    {
        node temp=head;
        while(temp.next.next!=null)
        {
            temp=temp.next;
        }
        node t=temp.next;
        temp.next.next=head.next;
        temp.next=head;
        head.next=null;
        return t;
    }
    public node insert(node head,int data[])
    {
        node t=null;
        for(int i=0;i<data.length;i++) {
            node temp = new node();
            temp.data=data[i];
            if (head == null) {
                head = temp;
                t = temp;
            } else {
                t.next = temp;
                t=temp;
            }
        }
        return head;
    }
    public void show(node head)
    {
        while(head!=null)
        {
            System.out.print(head.data+" ");
            head=head.next;
        }
        System.out.println();
    }



}
public class Para {
    public static void main(String []args) {
    node head=null;
        int arr[]={1,4,2,6,3,8};
        List l=new List();
        head=l.insert(head,arr);
        System.out.println("Before");
        l.show(head);
        head=l.moveL(head);
        System.out.println("After");
        l.show(head);
    }
}
