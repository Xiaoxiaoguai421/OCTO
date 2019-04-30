package com.example.zszx.node;

import org.neo4j.ogm.annotation.NodeEntity;

@NodeEntity
public class Score extends BaseEntity{
    private Integer sid;

    private double averageps;
    private double coline;
    private double minps;
    private double averages;
    private double maxps;
    private double difomac;
    private double cline;
    private double mins;
    private double difoaac;
    private double aline;
    private double maxs;

    private String subject;
    private String batch;
    private String remark;
    private String major;
    private String province;
    private String ctest;
    private String academy;

    /*
    private Integer sid;   //分数id
    private String province;   //省份
    private String subject; //科类（文科、理科、艺术、艺术文\理、 体育、体育文\理）
    private String batch;  //批次（本一、国家专项、地方专项等）
    private String  major; //专业
    private double maxs;  //最高分
    private double mins;  //最低分
    private double averages;  //平均分
    private double maxps; //最高专业分（针对体艺生）
    private double minps; //最低专业分
    private double averageps; //平均专业分
    private double aline; //录取线
    private double cline; //省控线
    private double coline;    //投档线
    private double difoaac;   //录取线高于省控线
    private double difomac;   //最低分高于省控线
    private String ctest; //选测科目（针对17年开始的上海和浙江的改革）
    private String remark;
    private String academy;   //学院
*/
    public Score() {

    }

    public Integer getSid() {
        return sid;
    }


    public void setSid(Integer sid) {
        this.sid = sid;
    }

    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    public String getBatch() {
        return batch;
    }

    public void setBatch(String batch) {
        this.batch = batch;
    }

    public String getRemark() {
        return remark;
    }

    public void setRemark(String remark) {
        this.remark = remark;
    }

    public String getMajor() {
        return major;
    }

    public void setMajor(String major) {
        this.major = major;
    }

    public String getProvince() {
        return province;
    }

    public void setProvince(String province) {
        this.province = province;
    }

    public String getCtest() {
        return ctest;
    }

    public void setCtest(String ctest) {
        this.ctest = ctest;
    }

    public String getAcademy() {
        return academy;
    }

    public void setAcademy(String academy) {
        this.academy = academy;
    }

    public double getAverageps() {
        return averageps;
    }

    public void setAverageps(double averageps) {
        this.averageps = averageps;
    }

    public double getColine() {
        return coline;
    }

    public void setColine(double coline) {
        this.coline = coline;
    }

    public double getMinps() {
        return minps;
    }

    public void setMinps(double minps) {
        this.minps = minps;
    }

    public double getAverages() {
        return averages;
    }

    public void setAverages(double averages) {
        this.averages = averages;
    }

    public double getMaxps() {
        return maxps;
    }

    public void setMaxps(double maxps) {
        this.maxps = maxps;
    }

    public double getDifomac() {
        return difomac;
    }

    public void setDifomac(double difomac) {
        this.difomac = difomac;
    }

    public double getCline() {
        return cline;
    }

    public void setCline(double cline) {
        this.cline = cline;
    }

    public double getMins() {
        return mins;
    }

    public void setMins(double mins) {
        this.mins = mins;
    }

    public double getDifoaac() {
        return difoaac;
    }

    public void setDifoaac(double difoaac) {
        this.difoaac = difoaac;
    }

    public double getAline() {
        return aline;
    }

    public void setAline(double aline) {
        this.aline = aline;
    }

    public double getMaxs() {
        return maxs;
    }

    public void setMaxs(double maxs) {
        this.maxs = maxs;
    }
}
