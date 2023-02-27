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
    public void show(node head)
    {
        while(head!=null)
        {
            System.out.print(head.data+" ");
            head=head.next;
        }
        System.out.println();
    }
    public void sort(node t1)
    {
        node head=t1;
        node t2=t1;
        while(t1!=null)
        {
            t2=head;
            while(t2!=null)
            {
                if(t1.data<t2.data)
                {
                    int t=t1.data;
                    t1.data=t2.data;
                    t2.data=t;
                }
                t2=t2.next;
            }
            t1=t1.next;
        }
    }

}
public class Para {
    public static void main(String []args) {
    node head=null;
        int arr[]={1,4,2,6,3,8};
        List l=new List();
        head=l.insert(head,arr);
        System.out.println("Before Sorting");
        l.show(head);
        l.sort(head);
        System.out.println("After Sorting");
        l.show(head);
    }
}
