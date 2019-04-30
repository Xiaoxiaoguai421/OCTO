package com.example.zszx.node;

import org.neo4j.ogm.annotation.NodeEntity;

@NodeEntity
public class Year extends BaseEntity{

    private Integer yid;
    private String year;

    public Year(){

    }

    public Integer getYid() {
        return yid;
    }

    public void setYid(Integer yid) {
        this.yid = yid;
    }

    public String getYear() {
        return year;
    }

    public void setYear(String year) {
        this.year = year;
    }
}
