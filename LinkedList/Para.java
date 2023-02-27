import java.util.*;
class node
{
    int data;
    node next;

}
class List
{

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
    public node reverse(node head)
    {
        node prev=null;
        node nextNode=null;
        while(head!=null)
        {
            nextNode=head.next;
            head.next=prev;
            prev=head;
            head=nextNode;
        }
        return prev;
    }
    public void show(node head)
    {
        if(head==null) {
            System.out.println();
            return;
        }
        System.out.print(head.data+" ");
        show(head.next);
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
        head=l.reverse(head);
        System.out.println("After");
        l.show(head);
    }
}
