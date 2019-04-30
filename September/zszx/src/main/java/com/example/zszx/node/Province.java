package com.example.zszx.node;

import org.neo4j.ogm.annotation.NodeEntity;

/*
    基于图形节点Province进行实体类Java类映射
 */

@NodeEntity
public class Province extends BaseEntity{
    private Integer pid;
    private String province;

    public Province(){

    }

    public Integer getPid() {
        return pid;
    }

    public void setPid(Integer pid) {
        this.pid = pid;
    }

    public String getProvince() {
        return province;
    }

    public void setProvince(String province) {
        this.province = province;
    }

}
