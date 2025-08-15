# CAN 学习与踩坑

## 学习内容
今天主要围绕 STM32 的 CAN 外设调试，包括：
- CAN1 和 CAN2 的互相通信
- 自发自收调试（Loopback 模式）
- 过滤器配置（16-bit ID List / Mask 模式）

---

## 基础认识
- **Normal 模式**：CAN 芯片只会接收其他节点的消息，不会收到自己发送的帧。
- **Loopback 模式**：内部回环，可以接收自己发送的消息，用于单片机未接总线时调试。
- **CAN1/CAN2 区别**：
  - CAN1 是主外设
  - CAN2 依赖 CAN1 的某些时钟与滤波器资源
- **CAN 收发线**：
  - 每个 CAN 接口都有两根线：`CAN_H` 和 `CAN_L`
  - 不同 CAN 口通信时要交叉连接：
    - CAN1_H ↔ CAN2_H
    - CAN1_L ↔ CAN2_L
  - 队里的CAN1有两个并联接口`can1-1`和`can1-2`, CAN2有`can2-1`和`can2-2`

---

## 坑

### Normal 模式收不到自己发的消息
- **原因**：CAN 协议规定正常模式下节点不会接收自己发出的帧。
- **解决**：调试阶段用 `CAN_MODE_LOOPBACK` 或外部回线连接 TX/RX。

---

### 16 位掩码模式理解错误
- **错误想法**：标准 ID 是 16 位，可以直接写 `0x0123`
- **实际情况**：
  - 标准 ID 只有 11 位
  - 存放在寄存器时需左移 5 位：`id << 5`
  - 16-bit scale 下高 16 位和低 16 位各能存一个 ID

---

### ID List 模式写了 Mask
- **原因**：ID List 模式是精确匹配，不使用 Mask
- **解决**：只设置 `FilterIdHigh` 和 `FilterIdLow`，不要管 Mask
---

## 调试方法
1. **单板调试**  
   Loopback 模式，不接总线
2. **双节点调试**  
    Normal 模式，CAN1 ↔ CAN2 交叉接线
3. **滤波器测试**：
   - 初期全 0 掩码接收所有帧
   - 再逐步加 ID 过滤
4. **FIFO 调试**：
   - 确认中断和 FIFO 分配一致
   - 回调里根据 `hcan->Instance` 和 FIFO 编号区分来源

---

## 4️⃣ 示例滤波器配置（16-bit ID List）
```c
CAN_FilterTypeDef filter;
filter.FilterBank = 0;
filter.FilterMode = CAN_FILTERMODE_IDLIST;
filter.FilterScale = CAN_FILTERSCALE_16BIT;
filter.FilterIdHigh = (0x123 << 5); // ID1
filter.FilterIdLow  = (0x124 << 5); // ID2
filter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
filter.FilterActivation = ENABLE;
filter.SlaveStartFilterBank = 14;
HAL_CAN_ConfigFilter(&hcan1, &filter);
