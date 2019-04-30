package com.example.zszx.repository;

import com.example.zszx.node.Year;
import org.springframework.data.neo4j.repository.Neo4jRepository;
import org.springframework.stereotype.Repository;

import java.util.List;


/*
      GraphRepository：Neo4j的图形存储库，继承该接口，实现Coder类的增删改查

 */
@Repository
public interface YearRepository extends Neo4jRepository<Year,Long> {
        List<Year> findByYear(String year);
}