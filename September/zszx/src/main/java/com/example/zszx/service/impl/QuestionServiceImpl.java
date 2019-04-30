package com.example.zszx.service.impl;

import com.example.zszx.ModelProcess;
import com.example.zszx.repository.QuestionRepository;
import com.example.zszx.service.QuestionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Service;

import java.util.ArrayList;

@Service
@Primary
public class QuestionServiceImpl implements QuestionService {

	@Autowired
	private QuestionRepository questionRepository;

	@Override
	public String answer(String question) throws Exception {

		ModelProcess queryProcess = new ModelProcess();	//直接使用无参构造函数制定路径
		ArrayList<String> reStrings = queryProcess.analyQuery(question);
		int modelIndex = Integer.valueOf(reStrings.get(0));
		String answer = null;
		String year = "";
		String province = "";
		/**
		 * 匹配问题模板
		 */
		switch (modelIndex) {
		case 0:
			/**
			 *	yy zy 省内招生计划
			 */
			break;
		case 1:
			/**
			 *  yy(年) pro(省) 分数线(查文理科,不包含上海)
			 */
			year = reStrings.get(1);
			province = reStrings.get(2);
			if(province.contains("省"))
				province=province.substring(0,province.length()-1);
			double mins=-1.0;
			double[] releaseDate = questionRepository.getMinsOfYear_Province_Subject(year,province,"理科");
			for(int i=0;i<releaseDate.length;i++)
			{
				if(releaseDate[i]>0.0 && mins<0)
					mins=releaseDate[i];
				else if(releaseDate[i]>0.0 && releaseDate[i]<mins){
					mins=releaseDate[i];
				}
			}
			releaseDate = questionRepository.getMinsOfYear_Province_Subject(year,province,"文科");
			for(int i=0;i<releaseDate.length;i++)
			{
				if(releaseDate[i]>0.0 && mins<0)
					mins=releaseDate[i];
				else if(releaseDate[i]>0.0 && releaseDate[i]<mins){
					mins=releaseDate[i];
				}
			}
			if (mins != -1.0) {
				answer = year+"年" + province+"的分数线为  "+mins+" 分.";
			} else {
				answer = null;
			}
			break;

		default:
			break;
		}

		System.out.println(answer);
		if (answer != null && !answer.equals("") && !answer.equals("\\N")) {
			return answer;
		} else {
			return "sorry,我没有找到你要的答案";
		}
	}
}
