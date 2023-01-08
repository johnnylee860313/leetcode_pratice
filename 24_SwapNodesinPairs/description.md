Given a linked list, 
swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

<img width="441" alt="截圖 2022-12-03 下午1 20 24" src="https://user-images.githubusercontent.com/42417212/205425313-d6aa0d91-d483-49f1-be54-38da13f69921.png">

![IMG_2585](https://user-images.githubusercontent.com/42417212/205425332-b08e5bd9-06db-4e43-83b5-ff7fe89ff106.JPG)

使用遞迴方式  
終止條件為此輪的head與head的下一個是否為空  
用意：  
1.head空的話代表找到最後一個節點的下一個（null）回傳給上一輪的head->next  讓倒數第二個節點能指向空. 
2.head->next為空的話代表此鏈為奇數個節點，直接回傳head給上一輪的head->next  
3.至此遞迴以致最底，完成將基數節點指向下一個基數節點。  
4.遞迴往回收的過程將偶數節點指向此輪的head
5.最後回傳第一個偶數節點
