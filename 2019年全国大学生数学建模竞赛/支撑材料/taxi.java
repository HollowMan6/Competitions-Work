import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;

public class taxi implements Runnable {

	String name;
	double profit;
	double time;
	int priority;
	static double l1, l2, L;
	static double Time = 24 * 60;
	static Queue<taxi> queue1 = new LinkedList<taxi>();
	static Queue<taxi> queue2 = new LinkedList<taxi>();
	static Queue<taxi> queue3 = new LinkedList<taxi>();

	public static void cleanqueue() {
		queue1.poll();
		queue2.poll();
		queue3.poll();
	}

	public static void main(String[] args) {
		double x1 = 8, x2 = 1.7, x3 = 2.25;// 3,3-9,9-??
		double y1 = 0.6;
		double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
		double[] min = new double[3];
		min[0] = 10000;
		min[1] = 10000;
		min[2] = 10000;
		Scanner sc = new Scanner(System.in);
		L = sc.nextDouble();// 输入L，则出租车一般载客距离为15km~(15+L)km
		for (l1 = 1; l1 <= L; l1 += 1)
			for (l2 = l1 + 1; l2 <= L; l2 += 1) {

				for (int i = 0; i <= 30; i++) {
					taxi aTaxi = new taxi("aTxi", 0, 24 * 60, 0);
					taxi bTaxi = new taxi("bTxi", 0, 24 * 60, 0);
					taxi cTaxi = new taxi("cTxi", 0, 24 * 60, 0);
					taxi dTaxi = new taxi("dTxi", 0, 24 * 60, 0);
					taxi eTaxi = new taxi("eTxi", 0, 24 * 60, 0);
					taxi fTaxi = new taxi("fTxi", 0, 24 * 60, 0);
					new Thread(aTaxi).start();
					new Thread(bTaxi).start();
					new Thread(cTaxi).start();
					new Thread(dTaxi).start();
					new Thread(eTaxi).start();
					new Thread(fTaxi).start();
					while (aTaxi.time >= 0 || bTaxi.time >= 0 || cTaxi.time >= 0 || dTaxi.time >= 0 || eTaxi.time >= 0
							|| fTaxi.time >= 0) {
						cleanqueue();
						try {
							Thread.sleep(15);
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
					sum1 += aTaxi.profit;
					sum2 += bTaxi.profit;
					sum3 += cTaxi.profit;
					sum4 += dTaxi.profit;
					sum5 += eTaxi.profit;
					sum6 += fTaxi.profit;

				}
				double tmp = fangcha(sum1, sum2, sum3, sum4, sum5, sum6);
				if (tmp <= min[0]) {
					min[0] = tmp;
					min[1] = l1;
					min[2] = l2;
				}

				sum1 = 0;
				sum2 = 0;
				sum3 = 0;
				sum4 = 0;
				sum5 = 0;
				sum6 = 0;
			}

		System.out.println("在路程范围为15~" + (15 + L) + "最合理的优先级划分为:\n" + "0~" + (min[1] + 15) + " " + (min[1] + 15) + "~"
				+ (min[2] + 15) + " " + (min[2] + 15) + "~" + (15 + L));
//		System.out.println("aTaxi的收益为:" + sum1);
//		System.out.println("bTaxi的收益为:" + sum2);
//		System.out.println("cTaxi的收益为:" + sum3);
//		System.out.println("dTaxi的收益为:" + sum4);
//		System.out.println("eTaxi的收益为:" + sum5);
//		System.out.println("fTaxi的收益为:" + sum6);
	}

	public static double fangcha(double a, double b, double c, double d, double e, double f) {
		double sum = (a + b + c + d + e + f) / 6;
		double f0 = (a - sum) * (a - sum) + (b - sum) * (b - sum) + (c - sum) * (c - sum) + (d - sum) * (d - sum)
				+ (e - sum) * (e - sum) + (f - sum) * (f - sum);
		return f0 / 6;
	}

	public taxi(String name, double profit, double time, int priority) {
		super();
		name = new String();
		this.name = name;
		this.profit = profit;
		this.time = time;
		this.priority = priority;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (time >= 0) {
			Random random = new Random();
			double distance = random.nextDouble() * L;// 随机生成一个1~L的距离
			double dist1 = distance + 15;// 基础距离为15km

			if (distance >= 0 && distance < l1)
				priority = 3;
			if (distance >= l1 && distance < l2)
				priority = 2;
			if (distance >= l2)
				priority = 1;

			time = time - 2 * (dist1 / 70.0) * 60;
			profit += pro(dist1);
			switch (priority) {
			case 1:
				p1();
			case 2:
				p2();
			case 3:
				p3();
			}
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}

	public double pro(double distance) {
		if (distance < 3)
			return 8;
		else if (distance >= 3 && distance < 9)
			return 8 + 1.7 * (distance - 3);
		else
			return 8 + 6 * 1.7 + (distance - 9) * 2.25;

	}

	public void p1() {
		queue1.offer(this);
		time -= (queue1.size() - 1) * 5;// 每辆车需耗时3min
	}

	public void p2() {
		if (queue1.size() <= queue2.size()) {
			queue1.offer(this);
			time -= (queue1.size() - 1) * 5;// 每辆车需耗时3min
		} else {
			queue2.offer(this);
			time -= (queue2.size() - 1) * 5;// 每辆车需耗时3min
		}
	}

	public void p3() {
		if (Math.max(Math.max(queue1.size(), queue2.size()), Math.max(queue1.size(), queue3.size())) == queue1.size()) {
			queue1.offer(this);
			time -= (queue1.size() - 1) * 5;// 每辆车需耗时3min
		} else if (Math.max(Math.max(queue1.size(), queue2.size()), Math.max(queue1.size(), queue3.size())) == queue2
				.size()) {
			queue2.offer(this);
			time -= (queue2.size() - 1) * 5;// 每辆车需耗时3min
		} else {
			queue3.offer(this);
			time -= (queue3.size() - 1) * 5;// 每辆车需耗时3min
		}
	}
}
