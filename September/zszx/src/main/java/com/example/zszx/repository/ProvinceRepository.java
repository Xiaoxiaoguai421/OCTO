package com.example.zszx.repository;

import com.example.zszx.node.Province;
import org.springframework.data.neo4j.repository.Neo4jRepository;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface ProvinceRepository extends Neo4jRepository<Province,Long> {
    List<Province> findByProvince(String province);
}
