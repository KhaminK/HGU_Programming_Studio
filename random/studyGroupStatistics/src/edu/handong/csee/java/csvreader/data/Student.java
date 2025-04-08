package edu.handong.csee.java.csvreader.data;

import java.util.ArrayList;

public class Student {
    private int group;
    private int memberID;
    private String name;
    private ArrayList<String> friends;
    private ArrayList<String> subjects;
    private int numOfReports;
    private int minsForStudy;

    public Student(String name){
        this.name = name;
    }
    
    public Student(String group, String memberID, String name, String friends, String subjects, String numOfReports,
            String minsForStudy) {
        this.group = Integer.parseInt(group);
        this.memberID = Integer.parseInt(memberID);
        this.name = name;
        String[] arrFriends = friends.split(", ");
        this.friends = new ArrayList<String>();
        for (String friendName : arrFriends) {
            this.friends.add(friendName);
        }
        String[] arrSubjects = subjects.split(", ");
        this.subjects = new ArrayList<String>();
        for (String subject : arrSubjects) {
            this.subjects.add(subject);
        }
        this.numOfReports = Integer.parseInt(numOfReports);
        this.minsForStudy = Integer.parseInt(minsForStudy);
    }

    public int getGroup() {
        return group;
    }

    public void setGroup(int group) {
        this.group = group;
    }

    public int getMemberID() {
        return memberID;
    }

    public void setMemberID(int memberID) {
        this.memberID = memberID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public ArrayList<String> getFriends() {
        return friends;
    }

    public void setFriends(ArrayList<String> friends) {
        this.friends = friends;
    }

    public ArrayList<String> getSubjects() {
        return subjects;
    }

    public void setSubjects(ArrayList<String> subjects) {
        this.subjects = subjects;
    }

    public int getNumOfReports() {
        return numOfReports;
    }

    public void setNumOfReports(int numOfReports) {
        this.numOfReports = numOfReports;
    }

    public int getMinsForStudy() {
        return minsForStudy;
    }

    public void setMinsForStudy(int minsForStudy) {
        this.minsForStudy = minsForStudy;
    }

}