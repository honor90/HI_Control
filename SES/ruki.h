/*
  (с) НТЦ "Модуль", 2000.

  В этом файле определены синонимы идентификаторов
  регистров, флагов и виртуальных регистров МСП,
  приводящие названия этих объетков в соответствие
  с документом ЮФКВ.469555.075РЭ "Ячейка МВ11.01.
  Руководство по эксплуатации"

*/

/*************************************************************************
  Регистры МКО
  0x00-0x0F регистры хост-интерфейса (BU-61580)
  0x10-0x1F регистры хост-интерфейса не используемые (BU-61580)
  0x20-0x21	регистры БКР: старший байт не используется
  0x40-???	регистры КПИ (не реализовано)
**************************************************************************/

#define		imr			mspRR_INTERRUPT_MASK
#define		cfg1_		mspRR_CONFIG1
#define		cfg2_		mspRR_CONFIG2
#define		ssr			mspRR_COMMAND
#define		cspr		mspRR_COMMAND_STACK_POINTER

#define		bc_cw		mspRR_CONTROL_WORD
#define		rt_cw		mspRR_CONTROL_WORD

#define		tt_reg		mspRR_TIME_TAG
#define		isr			mspRR_INTERRUPT_STATUS
#define		cfg3_		mspRR_CONFIG3
#define		cfg4_		mspRR_CONFIG4
#define		cfg5_		mspRR_CONFIG5
//lve
#define		cfg6_		mspRR_CONFIG6
#define		rm_dsa		mspRR_DATA_STACK_ADDRESS
#define		bc_ftr		mspRR_FRAME_TIME_REMAINING
#define		bc_trnm		mspRR_MESSAGE_TIME_REMAINING
#define		bcft		mspRR_BC_FRAME_TIME
#define		rtlc		mspRR_RT_LAST_COMMAND
#define		mttw		mspRR_MT_TRIGGER
#define         bcft_rtlc_mttw  bcft
#define		rt_sw		mspRR_RT_STATUS_WORD
#define		rt_bit_w	mspRR_RT_BIT_WORD

/*************************************************************************
  Регистры конрроллера PCI 9050
  Эти значения не являются частью спецификации RTL
  и могут не поддерживаться в других версиях и на
  других платформах
**************************************************************************/


#define LAS0RR		0x00
#define LAS1RR		0x01
#define LAS2RR		0x02
#define LAS3RR		0x03
#define EROMRR		0x04
#define LAS0BA		0x05
#define LAS1BA		0x06
#define LAS2BA		0x07
#define LAS3BA		0x08
#define EROMBA		0x09
#define LAS0BRD		0x0A
#define LAS1BRD		0x0B
#define LAS2BRD		0x0C
#define LAS3BRD		0x0D
#define EROMBRD		0x0E
#define CS0BASE		0x0F
#define CS1BASE		0x10
#define CS2BASE		0x11
#define CS3BASE		0x12
#define INTCSR		0x13
#define CNTRL		0x14

/***************************************************************
        Flags & virtual regisers definition
 ***************************************************************/

//Common flags
#define ca_b_a		mspF_CURRENT_AREA
#define ca_b		mspF_CURRENT_AREA_B
#define ca_a		mspF_CURRENT_AREA_A

#define _12mhz		mspF_LOWER_CLOCK_SELECT
#define	ece			mspF_DOUBLE_SAMPLE_FREQUENCY
#define gce			mspF_GAP_CHECK_ENABLED
#define	_256_wbd	mspF_256WORD_BOUNDARY_DISABLE
#define	eme			mspF_ENHANCED_MODE


//BC mode flags

#define m_soe		mspF_MESSAGE_STOP_ON_ERROR
#define f_soe		mspF_FRAME_STOP_ON_ERROR
#define	ss_som		mspF_STATUS_SET_STOP_ON_MESSSAGE
#define ss_sof		mspF_STATUS_SET_STOP_ON_FRAME
#define far_		mspF_FRAME_AUTOREPEAT
#define ete			mspF_EXTERNAL_TRIGGER_ENABLED
#define ite			mspF_INTERNAL_TRIGGER_ENABLED
#define imgte		mspF_MESSAGE_GAP_TIMER_ENABLED
#define re			mspF_RETRY_ENABLED
#define ds_r		mspF_DOUBLE_RETRY
#define bc_e		mspF_BC_ENABLED
#define	bc_fip		mspF_BC_FRAME_IN_PROGRESS
#define bc_mip		mspF_BC_MESSAGE_IN_PROGRESS

#define e_bc_cwe	mspF_EXPANDED_BC_CONTROL_WORD
#define	bm_ex		mspF_BROADCAST_MASK_ENABLED
#define	ri_aame		mspF_RETRY_IF_1553A_AND_MESSAGE_ERROR
#define	ri_ss		mspF_RETRY_IF_STATUS_SET
#define	_1r_asb		mspF_RETRY1_AT_ALT_BUS
#define	_2r_asb		mspF_RETRY2_AT_ALT_BUS
#define	v_me_nd		mspF_VALID_ERROR_BIT_NO_DATA
#define	v_b_nd		mspF_VALID_BUSY_BIT_NO_DATA


//RT mode flags

#define not_dbca	mspF_NOT_ACCEPT_DYNAMIC_BUS_CONTROL
#define dbca		mspF_ACCEPT_DYNAMIC_BUS_CONTROL
#define not_busy	mspF_NOT_BUSY
#define busy		mspF_BUSY
#define not_sr		mspF_NOT_SERVICE_REQUEST
#define sr			mspF_SERVICE_REQUEST
#define not_sf		mspF_NOT_SUBSYSTEM_FLAG
#define sf			mspF_SUBSYSTEM_FLAG
#define not_rtf		mspF_NOT_RTFLAG
#define rtf			mspF_RTFLAG
#define rt_mip		mspF_RT_MESSAGE_IN_PROGRESS

#define S10         MakeFLAGID(mspRR_CONFIG1, 11)
#define S09         MakeFLAGID(mspRR_CONFIG1, 10)
#define S08         MakeFLAGID(mspRR_CONFIG1, 9)
#define S07         MakeFLAGID(mspRR_CONFIG1, 8)
#define S06         MakeFLAGID(mspRR_CONFIG1, 7)
#define S05         MakeFLAGID(mspRR_CONFIG1, 6)
#define S04         MakeFLAGID(mspRR_CONFIG1, 5)
#define S03         MakeFLAGID(mspRR_CONFIG1, 4)
#define S02         MakeFLAGID(mspRR_CONFIG1, 3)
#define S01         MakeFLAGID(mspRR_CONFIG1, 2)
#define S00         MakeFLAGID(mspRR_CONFIG1, 1)

#define alt_me     S10
#define alt_instr  S09
#define alt_sr     S08
#define alt_bcr	   S04
#define alt_busy   S03
#define alt_sf     S02
#define alt_dbca   S01
#define alt_tf     S00

#define blute		mspF_BUSY_BIT_LOOKUP_TABLE_ENABLE
#define rsdbe		mspF_DOUBLE_BUFFERING_ENABLE
#define oid			mspF_OVERWRITE_INVALID_DATA
#define c_ttos		mspF_CLEAR_TIME_TAG_ON_SYNCHRONIZE
#define l_ttos		mspF_LOAD_TIME_TAG_ON_SYNCHRONIZE
#define csr			mspF_CLEAR_SERVICE_REQUEST
#define ertmm		mspF_ENHANCED_RT_MEMORY_MANAGEMENT
#define sbd			mspF_SEPARATE_BROADCAST_DATA
#define id			mspF_ILLEGALIZATION_DISABLED
#define ome			mspF_OVERRIDE_MODE_CODE_BIT_ERROR
#define aswe		mspF_ALTERNATE_RT_STATUS_WORD_ENABLED
#define i_rx_td		mspF_ILLEGAL_RECEIVE_TRANSFER_DISABLE
#define b_rx_td		mspF_BUSY_RECEIVE_TRANSFER_DISABLE
#define rt_f_we		mspF_RTF_WRAP_ENABLE
#define _1553a_mce	mspF_1553A_MODE_CODES_ENABLED
#define emch		mspF_ENHANCED_MODE_CODE_HANDLING
#define ebwe		mspF_EXTERNAL_BIT_WORD_ENABLE
#define ibwib		mspF_INHIBIT_BIT_WORD_TRANSMIT_IF_BUSY
#define mcob		mspF_MODE_CODE_OVERRIDE_BUSY
#define bd			mspF_BROADCAST_DISABLED

//MT mode flags
#define tew		mspF_MONITOR_TRIGGER_ENABLED
#define st_ot	mspF_START_ON_TRIGGER
#define sp_ot	mspF_STOP_ON_TRIGGER
#define mete	mspF_EXTERNAL_TRIGGER_ENABLED
#define m_e		mspF_MONITOR_ENABLED
#define m_t		mspF_MONITOR_TRIGGERED
#define m_a		mspF_MONITOR_ACTIVE
#define _1553a_mce	mspF_1553A_MODE_CODES_ENABLED
#define mtgo	mspF_MONITOR_TAG_GAP_OPTION

//Interrupt control flags
#define ei		mspF_ENHANCED_INTERRUPTS
#define isac	mspF_INTERRUPT_STATUS_AUTO_CLEAR
#define l_ir	mspF_LEVEL_INTERRUPTS
#define p_ir	mspF_PULSE_INTERRUPTS

//Virtual registers
#define vr_rt_cw	MakeALIAS(rt_cw)
#define vr_tt_rsl	mspR_TIME_TAG_RESOLUTION 
        //Значения:
        #define tt_rsl_64us		msp_TIME_TAG_RESOLUTION_64us
        #define tt_rsl_32us		msp_TIME_TAG_RESOLUTION_32us 
        #define tt_rsl_16us		msp_TIME_TAG_RESOLUTION_16us
        #define tt_rsl_8us		msp_TIME_TAG_RESOLUTION_8us 
        #define tt_rsl_4us		msp_TIME_TAG_RESOLUTION_4us 
        #define tt_rsl_2us		msp_TIME_TAG_RESOLUTION_2us 
        #define tt_rsl_tm		msp_TIME_TAG_RESOLUTION_TEST_MODE
        #define tt_rsl_eclk		msp_TIME_TAG_RESOLUTION_EXT_CLOCK

#define csp			mspRR_COMMAND_STACK_POINTER
#define	vr_csp		MakeALIAS(csp)
#define vr_bc_cw	MakeALIAS(bc_cw)
#define vr_tt_reg	MakeALIAS(tt_reg)
#define vr_bt_csz		mspR_COMMAND_STACK_SIZE
//Для режимов КШ/ОУ.
        //Значения:
        #define bt_csz_64	msp_STACK_SIZE_64
        #define bt_csz_128	msp_STACK_SIZE_128
        #define bt_csz_256	msp_STACK_SIZE_256
        #define bt_csz_512	msp_STACK_SIZE_512
        //(размер – в сообщениях)
#define vr_mt_csz		mspR_MT_COMMAND_STACK_SIZE 
//Для режима МТ.
        //Значения:
        #define mt_csz_64	msp_MT_CSTACK_SIZE_64
        #define mt_csz_256	msp_MT_CSTACK_SIZE_256
        #define mt_csz_1024	msp_MT_CSTACK_SIZE_1024
        #define mt_csz_4096	msp_MT_CSTACK_SIZE_4096
        //(размер – в сообщениях)
#define vr_mt_dsz		mspR_MT_DATA_STACK_SIZE 
//Для режима МТ.
        //Значения:
        #define mt_dsz_64K	msp_MT_DSTACK_SIZE_64K
        #define mt_dsz_32K	msp_MT_DSTACK_SIZE_32K
        #define mt_dsz_16K	msp_MT_DSTACK_SIZE_16K
        #define mt_dsz_8K	msp_MT_DSTACK_SIZE_8K
        #define mt_dsz_4K	msp_MT_DSTACK_SIZE_4K
        #define mt_dsz_2K	msp_MT_DSTACK_SIZE_2K
        #define mt_dsz_1K	msp_MT_DSTACK_SIZE_1K
        #define mt_dsz_512	msp_MT_DSTACK_SIZE_512
        //(размер – в словах)
#define vr_rts	mspR_RESPONSE_TIMEOUT
        //Значения:
        #define rts_18us5	msp_RESPONSE_TIMEOUT_18us5
        #define rts_22us5	msp_RESPONSE_TIMEOUT_22us5
        #define rts_50us5	msp_RESPONSE_TIMEOUT_50us5
        #define rts_130us	msp_RESPONSE_TIMEOUT_130us

#define vr_rm_dsa		 MakeALIAS(rm_dsa)
#define vr_bc_ftr		 MakeALIAS(bc_ftr)
#define vr_bc_trnm		 MakeALIAS(bc_trnm)
#define vr_bcft          MakeALIAS(bcft)
#define vr_rtlc          vr_bcft
#define vr_mttw          vr_bcft
#define vr_bcft_rtlc_mttw vr_bcft	
#define vr_rt_sw         MakeALIAS(rt_sw)
#define vr_rt_bit_w      MakeALIAS(rt_bit_w)
#define vr_imr           MakeALIAS(imr)
#define vr_isr           MakeALIAS(isr)

        //imr и isr - комбинации бит.
        //Кодировка бит:
        #define i_mi		mspM_MASTER_INTERRUPT		 /*только isr*/
        #define i_rp_er		mspM_RAM_PARITY_ERROR
        #define i_bt_tt		mspM_TRANSMITTER_TIMEOUT
        #define i_bt_csr	mspM_COMMAND_STACK_ROLLOVER
        #define i_mt_csr	mspM_MT_COMMAND_STACK_ROLLOVER
        #define i_mt_dsr	mspM_MT_DATA_STACK_ROLLOVER
        #define i_hf		mspM_HANDSHAKE_FAILURE
        #define i_bc_r		mspM_BC_RETRY
        #define i_rt_ape	mspM_RT_ADDRESS_PARITY_ERROR
        #define i_tt_rol	mspM_TIME_TAG_ROLLOVER
        #define i_rt_cbr	mspM_RT_CIRCULAR_BUFFER_ROLLOVER
        #define i_scw_s_e	mspM_SACW_EOM
        #define i_bc_eof	mspM_BC_EOF 
        #define i_fe		mspM_FORMAT_ERROR
        #define i_ss_mc_pt	mspM_BC_STATUS_SET
		#define	i_eom		mspM_EOM

#define vr_rt_a	mspR_RT_ADDRESS

/***************************************************************
        Command functions
 ***************************************************************/

#define srr_reset		mspC_RESET
#define srr_start		mspC_START
#define srr_ir			mspC_INTERRUPT_RESET
#define srr_tt_rst		mspC_TIME_TAG_RESET
#define srr_tttc		mspC_TIME_TAG_TEST_CLOCK
#define srr_bc_sof		mspC_STOP_ON_FRAME
#define srr_bt_som		mspC_STOP_ON_MESSAGE

/***************************************************************
        1553 messages
 ***************************************************************/

//Status decode
#define s_rt_a		msp_STATUS_RTADD_MASK	
#define s_me		msp_STATUS_MESSAGE_ERROR				
#define s_instr		msp_STATUS_INSTRUMENTATION				
#define s_sr		msp_STATUS_SERVICE_REQUEST				
#define s_bcr		msp_STATUS_BROADCAST_COMMAND_RECEIVED   
#define s_busy		msp_STATUS_BUSY							
#define s_sf		msp_STATUS_SUBSYSTEM_FLAG				
#define s_dbca		msp_STATUS_DYNAMIC_BUS_CONTROL_ACCEPTED 
#define s_tf		msp_STATUS_TERMINAL_FLAG				

/***************************************************************
        Constants & data types for stacks & frames
 ***************************************************************/

//Block Status Word bits

#define bsw_eom		msp_BSW_EOM
#define bsw_som		msp_BSW_SOM
#define bsw_ch_a_b	msp_BSW_CHANNEL_B
#define bsw_ef		msp_BSW_ERROR_FLAG
#define bsw_fe		msp_BSW_FORMAT_ERROR
#define bsw_r_tt	msp_BSW_NO_RESPONSE_TIMEOUT

#define bsw_ss			msp_BSW_BC_STATUS_SET
#define bsw_bc_ltf		msp_BSW_BC_LOOP_TEST_FAIL
#define bsw_mss			msp_BSW_BC_MASKED_STATUS_SET
#define bsw_re_co1		msp_BSW_BC_DOUBLE_RETRY
#define bsw_re_co0		msp_BSW_BC_SINGLE_RETRY
#define bsw_bc_gdbt		msp_BSW_BC_GOOD_DATA_BLOCK_TRANSFER
#define bsw_bc_wca_ng	msp_BSW_BC_STATUS_RESPONSE_ERROR
#define bsw_bc_wce		msp_BSW_BC_WORD_COUNT_ERROR
#define bsw_bc_ist		msp_BSW_BC_INCORRECT_SYNC_TYPE
#define bsw_bc_iw		msp_BSW_BC_INVALID_WORD

#define bsw_rt_rt_rt_f	msp_BSW_RT_RT_TO_RT
#define bsw_rt_ltf		msp_BSW_RT_LOOP_TEST_FAIL
#define bsw_rt_dsr		msp_BSW_RT_DATA_STACK_ROLLOVER
#define bsw_rt_icw		msp_BSW_RT_ILLEGAL_COMMAND_WORD
#define bsw_rt_wce		msp_BSW_RT_WORD_COUNT_ERROR
#define bsw_rt_ids		msp_BSW_RT_INCORRECT_DATA_SYNC
#define bsw_rt_iw		msp_BSW_RT_INVALID_WORD
#define bsw_rt_rtg_s_ae	msp_BSW_RT_STATUS_RESPONSE_ERROR
#define bsw_rt_rt_2cwe	msp_BSW_RT_SECOND_COMMAND_ERROR
#define bsw_rt_cwce		msp_BSW_RT_COMMAND_WORD_ERROR

#define bsw_mm_rt_rt_f	msp_BSW_MM_RT_TO_RT
#define bsw_mm_gdbt		msp_BSW_MM_GOOD_DATA_BLOCK_TRANSFER
#define bsw_mm_dsr		msp_BSW_MM_DATA_STACK_ROLLOVER 
#define bsw_mm_wce		msp_BSW_MM_WORD_COUNT_ERROR
#define bsw_mm_ids		msp_BSW_MM_INCORRECT_DATA_SYNC
#define bsw_mm_iw		msp_BSW_MM_INVALID_WORD
#define bsw_mm_rtg_s_ae	msp_BSW_MM_STATUS_RESPONSE_ERROR
#define bsw_mm_rt_2cwe	msp_BSW_MM_SECOND_COMMAND_ERROR
#define bsw_mm_cwce		msp_BSW_MM_COMMAND_WORD_ERROR

/***************************************************************
    Polymorphic functions for stacks & frames
 ***************************************************************/

//Константы для BCCW:
//В msp_CreateMessage Биты 0-2 заполняются автоматически согласно buffer->type
//Не надо их задавать

#define bccw_rt_rt_f	msp_BCCW_RT_TO_RT_FORMAT
#define bccw_bf			msp_BCCW_BROADCAST_FORMAT
#define bccw_mcf		msp_BCCW_MODE_CODE_FORMAT
#define bccw_1553_a		msp_BCCW_1553A
#define bccw_1553_b		msp_BCCW_1553B
#define bccw_eom_ie		msp_BCCW_EOM_INTR_ENABLE
#define bccw_mbb		msp_BCCW_MASK_BROADCAST			
#define bccw_olst		msp_BCCW_SELFTEST				
#define bccw_bc_a		msp_BCCW_CHANNEL_A				
#define bccw_bc_b		msp_BCCW_CHANNEL_B				
#define bccw_re			msp_BCCW_RETRY_ENABLED			
#define bccw_rbm		msp_BCCW_RESERVED_MASK			
#define bccw_tfbm		msp_BCCW_TERMINAL_FLAG_MASK		
#define bccw_sfbm		msp_BCCW_SUBSYSTEM_FLAG_MASK	
#define bccw_sbbm		msp_BCCW_BUSY_MASK				
#define bccw_srbm		msp_BCCW_SERVICE_REQUEST_MASK	
#define bccw_mem		msp_BCCW_MESSAGE_ERROR_MASK		

/***************************************************************
    Word monitor status decode 
 ***************************************************************/

#define wm_gt		msp_WM_GAP_TIME_mask
#define wm_wf		msp_WM_WORD_FLAG
#define wm_n_this_rt	msp_WM_N_THIS_RT
#define	wm_n_brcst	msp_WM_N_BROADCAST
#define wm_error	msp_WM_ERROR
#define wm_com_dat	msp_WM_SYNC_TYPE //1 for command, 0 for data
#define wm_ch_b_a	msp_WM_CHANNEL	 //1 for B, 0 for A
#define wm_cd_g		msp_WM_N_GAP
#define wm_mc		msp_WM_N_MODECODE

/***************************************************************
    Extensions for multiport devices
 ***************************************************************/
#define rbia		mspRR_MRT_ADDRESS
#define	mrt_cfg1_	mspRR_MRT_CONFIG1
#define mrt_sr		mspRR_MRT_STATUS
#define isr_fifo	mspRR_MRT_INTERRUPT_STATUS
#define mrt_cw		mspRR_MRT_COMMAND_WORD
#define mrt_sw		mspRR_MRT_STATUS_WORD

#define mrt_en			mspF_MULTIRT_ENABLE

#define vr_rbia			mspR_MRT_ADDRESS
#define	vr_mrt_cfg1_	mspR_MRT_CONFIG1
	#define m_S10		mspF_MRT_S10
	#define m_S09		mspF_MRT_S09
	#define m_S08		mspF_MRT_S08
	#define m_S07		mspF_MRT_S07
	#define m_S06		mspF_MRT_S06
	#define m_S05		mspF_MRT_S05
	#define m_S04		mspF_MRT_S04
	#define m_S03		mspF_MRT_S03
	#define m_S02		mspF_MRT_S02
	#define m_S01		mspF_MRT_S01
	#define m_S00		mspF_MRT_S00
	#define m_not_dbca	mspF_MRT_NOT_ACCEPT_DYNAMIC_BUS_CONTROL
	#define m_dbca		mspF_MRT_ACCEPT_DYNAMIC_BUS_CONTROL
	#define m_busy		mspF_MRT_BUSY
	#define m_not_sr		mspF_MRT_NOT_SERVICE_REQUEST
	#define m_sr			mspF_MRT_SERVICE_REQUEST
	#define m_not_sf		mspF_MRT_NOT_SUBSYSTEM_FLAG
	#define m_sf			mspF_MRT_SUBSYSTEM_FLAG
	#define m_not_rtf		mspF_MRT_NOT_RTFLAG
	#define m_rtf			mspF_MRT_RTFLAG
#define vr_mrt_sr		mspR_MRT_STATUS
	#define mrt_mip		mspF_MRT_MESSAGE_IN_PROGRESS
	#define isr_fifo_cnt	mspR_MRT_ISR_FIFO_COUNTER
	#define vr_isr_fifo_cnt	mspR_MRT_ISR_FIFO_COUNTER
	#define a_Rtadr		mspR_MRT_ACTIVE_RT
	#define vr_Rtadr	mspR_MRT_ACTIVE_RT
#define vr_isr_fifo		mspR_MRT_INTERRUPT_STATUS
	#define Rtadr		mspR_MRT_ISR_RT_ADDRESS
	#define bt_tt		mspM_MRT_TRANSMITTER_TIMEOUT
    #define bt_csr		mspM_MRT_COMMAND_STACK_ROLLOVER
    #define bt_hf		mspM_MRT_HANDSHAKE_FAILURE
    #define tt_rol		mspM_MRT_TIME_TAG_ROLLOVER
    #define rt_cbr		mspM_MRT_RT_CIRCULAR_BUFFER_ROLLOVER
    #define scw_e		mspM_MRT_SACW_EOM
    #define fe			mspM_MRT_FORMAT_ERROR
    #define ss_mc_pt	mspM_MRT_RT_MODE_CODE
    #define eom			mspM_MRT_EOM
#define vr_mrt_cw		mspR_MRT_COMMAND_WORD
#define vr_mrt_sw		mspR_MRT_STATUS_WORD

/***************************************************************
    GSW
 ***************************************************************/
#define gsw_dsp		        mspRR_WG_DATA_STACK_POINTER
#define gsw_dsa                 mspRR_WG_INITIAL_DATA_STACK_POINTER


